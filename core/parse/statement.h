
enum StatementType {
    STATEMENT_EXIT,
    STATEMENT_INSERT, 
    STATEMENT_SELECT
};

struct Statement {
    StatementType type;
};