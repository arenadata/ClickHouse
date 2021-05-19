#include <Common/assert_cast.h>
#include <Interpreters/NullableUtils.h>


namespace DB
{

ColumnPtr extractNestedColumnsAndNullMap(ColumnRawPtrs & key_columns, ConstNullMapPtr & null_map)
{
    ColumnPtr null_map_holder;

    if (key_columns.size() == 1)
    {
        auto & column = key_columns[0];
        if (const auto * column_nullable = checkAndGetColumn<ColumnNullable>(*column))
        {
            null_map_holder = column_nullable->getNullMapColumnPtr();
            null_map = &column_nullable->getNullMapData();
            column = &column_nullable->getNestedColumn();
        }
    }
    else
    {
        for (auto & column : key_columns)
        {
            if (const auto * column_nullable = checkAndGetColumn<ColumnNullable>(*column))
            {
                column = &column_nullable->getNestedColumn();

                if (!null_map_holder)
                {
                    null_map_holder = column_nullable->getNullMapColumnPtr();
                }
                else
                {
                    MutableColumnPtr mutable_null_map_holder = IColumn::mutate(std::move(null_map_holder));

                    PaddedPODArray<UInt8> & mutable_null_map = assert_cast<ColumnUInt8 &>(*mutable_null_map_holder).getData();
                    const PaddedPODArray<UInt8> & other_null_map = column_nullable->getNullMapData();
                    for (size_t i = 0, size = mutable_null_map.size(); i < size; ++i)
                        mutable_null_map[i] |= other_null_map[i];

                    null_map_holder = std::move(mutable_null_map_holder);
                }
            }
        }

        null_map = null_map_holder ? &assert_cast<const ColumnUInt8 &>(*null_map_holder).getData() : nullptr;
    }

    return null_map_holder;
}

ColumnPtr joinNullMaps(Columns & null_map_holder_vector, ConstNullMapPtrVector & null_map_vector, ConstNullMapPtr & null_map)
{
    ColumnPtr null_map_holder = null_map_holder_vector[0];
    MutableColumnPtr mutable_null_map_holder = IColumn::mutate(std::move(null_map_holder));
    PaddedPODArray<UInt8> & mutable_null_map = assert_cast<ColumnUInt8 &>(*mutable_null_map_holder).getData();

    for (size_t i = 1, vsize = null_map_vector.size(); i < vsize; ++i)
    {
        ColumnPtr other_null_map_holder = null_map_holder_vector[i];
        MutableColumnPtr other_mutable_null_map_holder = IColumn::mutate(std::move(other_null_map_holder));
        PaddedPODArray<UInt8> & other_mutable_null_map = assert_cast<ColumnUInt8 &>(*other_mutable_null_map_holder).getData();

        for (size_t j = 0, msize = mutable_null_map.size(); j < msize; ++j)
            mutable_null_map[j] &= other_mutable_null_map[j];

    }

    null_map_holder = std::move(mutable_null_map_holder);
    null_map = null_map_holder ? &assert_cast<const ColumnUInt8 &>(*null_map_holder).getData() : nullptr;

    return null_map_holder;
}


}
