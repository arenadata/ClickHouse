LIBRARY()

ADDINCL(
    contrib/libs/libdivide
    contrib/libs/pdqsort
)

PEERDIR(
    clickhouse/src/Core
    contrib/libs/libdivide
    contrib/libs/pdqsort
)

NO_COMPILER_WARNINGS()

SRCS(
    ActionLocksManager.cpp
    ActionsVisitor.cpp
    addMissingDefaults.cpp
    addTypeConversionToAST.cpp
    AggregateDescription.cpp
    Aggregator.cpp
    AnyInputOptimize.cpp
    ArithmeticOperationsInAgrFuncOptimize.cpp
    ArithmeticOperationsInAgrFuncOptimize.h
    ArrayJoinAction.cpp
    AsynchronousMetrics.cpp
    BloomFilter.cpp
    castColumn.cpp
    CatBoostModel.cpp
    ClientInfo.cpp
    Cluster.cpp
    ClusterProxy/executeQuery.cpp
    ClusterProxy/SelectStreamFactory.cpp
    CollectJoinOnKeysVisitor.cpp
    Context.cpp
    convertFieldToType.cpp
    createBlockSelector.cpp
    CrossToInnerJoinVisitor.cpp
    DatabaseAndTableWithAlias.cpp
    DatabaseCatalog.cpp
    DDLWorker.cpp
    DictionaryReader.cpp
    DNSCacheUpdater.cpp
    EmbeddedDictionaries.cpp
    evaluateConstantExpression.cpp
    executeQuery.cpp
    ExecuteScalarSubqueriesVisitor.cpp
    ExpressionActions.cpp
    ExpressionAnalyzer.cpp
    ExternalDictionariesLoader.cpp
    ExternalLoader.cpp
    ExternalLoaderDatabaseConfigRepository.cpp
    ExternalLoaderTempConfigRepository.cpp
    ExternalLoaderXMLConfigRepository.cpp
    ExternalModelsLoader.cpp
    ExtractExpressionInfoVisitor.cpp
    FillingRow.cpp
    getClusterName.cpp
    getTableExpressions.cpp
    HashJoin.cpp
    IdentifierSemantic.cpp
    IExternalLoadable.cpp
    RemoveInjectiveFunctionsVisitor.cpp
    InJoinSubqueriesPreprocessor.cpp
    inplaceBlockConversions.cpp
    InternalTextLogsQueue.cpp
    InterpreterAlterQuery.cpp
    InterpreterCheckQuery.cpp
    InterpreterCreateQuery.cpp
    InterpreterCreateQuotaQuery.cpp
    InterpreterCreateRoleQuery.cpp
    InterpreterCreateRowPolicyQuery.cpp
    InterpreterCreateSettingsProfileQuery.cpp
    InterpreterCreateUserQuery.cpp
    InterpreterDescribeQuery.cpp
    InterpreterDropAccessEntityQuery.cpp
    InterpreterDropQuery.cpp
    InterpreterExistsQuery.cpp
    InterpreterExplainQuery.cpp
    InterpreterFactory.cpp
    InterpreterGrantQuery.cpp
    InterpreterInsertQuery.cpp
    InterpreterKillQueryQuery.cpp
    InterpreterOptimizeQuery.cpp
    InterpreterRenameQuery.cpp
    InterpreterSelectQuery.cpp
    InterpreterSelectWithUnionQuery.cpp
    InterpreterSetQuery.cpp
    InterpreterSetRoleQuery.cpp
    InterpreterShowAccessQuery.cpp
    InterpreterShowAccessEntitiesQuery.cpp
    InterpreterShowCreateAccessEntityQuery.cpp
    InterpreterShowCreateQuery.cpp
    InterpreterShowGrantsQuery.cpp
    InterpreterShowPrivilegesQuery.cpp
    InterpreterShowProcesslistQuery.cpp
    InterpreterShowTablesQuery.cpp
    InterpreterSystemQuery.cpp
    InterpreterUseQuery.cpp
    InterpreterWatchQuery.cpp
    interpretSubquery.cpp
    join_common.cpp
    JoinedTables.cpp
    JoinSwitcher.cpp
    JoinToSubqueryTransformVisitor.cpp
    loadMetadata.cpp
    LogicalExpressionsOptimizer.cpp
    MarkTableIdentifiersVisitor.cpp
    MergeJoin.cpp
    MetricLog.cpp
    AsynchronousMetricLog.cpp
    MutationsInterpreter.cpp
    NullableUtils.cpp
    OptimizeIfChains.cpp
    OptimizeIfWithConstantConditionVisitor.cpp
    PartLog.cpp
    PredicateExpressionsOptimizer.cpp
    PredicateRewriteVisitor.cpp
    ProcessList.cpp
    ProfileEventsExt.cpp
    QueryAliasesVisitor.cpp
    QueryLog.cpp
    QueryNormalizer.cpp
    QueryThreadLog.cpp
    RenameColumnVisitor.cpp
    ReplaceQueryParameterVisitor.cpp
    RequiredSourceColumnsData.cpp
    RequiredSourceColumnsVisitor.cpp
    RowRefs.cpp
    Set.cpp
    SetVariants.cpp
    sortBlock.cpp
    SortedBlocksWriter.cpp
    StorageID.cpp
    SubqueryForSet.cpp
    SyntaxAnalyzer.cpp
    SystemLog.cpp
    TableJoin.cpp
    TablesStatus.cpp
    TextLog.cpp
    ThreadStatusExt.cpp
    TraceLog.cpp
    TranslateQualifiedNamesVisitor.cpp
)

END()
