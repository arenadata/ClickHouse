#pragma once
#include <Columns/ColumnNullable.h>


namespace DB
{

/** Replace Nullable key_columns to corresponding nested columns.
  * In 'null_map' return a map of positions where at least one column was NULL.
  * @returns ownership column of null_map.
  */
ColumnPtr extractNestedColumnsAndNullMap(ColumnRawPtrs & key_columns, ConstNullMapPtr & null_map);


/** In 'null_map' return a map of positions where all column of null_map_vector was NULL.
  * @returns ownership column of null_map.
  */
ColumnPtr joinNullMaps(Columns & null_map_holder_vector, ConstNullMapPtrVector & null_map_vector, ConstNullMapPtr & null_map);

}
