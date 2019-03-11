// token
enum {
    TK_NUM = 256, // Integer
    TK_IDENT,
    TK_EOF,
};

typedef struct {
    int ty; // TK_NUM, TK_EOF, ...
    int val; // TK_NUM => value
    int *input; // token string for error msg
} Token;

void tokenize(char *p);
void error(int i);

enum {
    ND_NUM = 256,
    ND_IDENT,
};

// ast
typedef struct Node {
    int ty;
    struct Node *lhs;
    struct Node *rhs;
    int val; // ND_NUM only
    char name; // ND_IDENT only
} Node;

Node *new_node(int ty, Node *lhs, Node *rhs);
Node *new_node_num(int val);
int consume(int ty);

// parse
void program();
Node *stmt();
Node *add();
Node *mul();
Node *term();

// gen code
void gen_lval(Node *node);
void gen(Node *node);

// container
typedef struct {
    void **data;
    int capacity;
    int len
} Vector;

Vector *new_vector();
void vec_push(Vector *vec, void *elem);
void test_vector();

typedef struct {
    Vector *keys;
    Vector *vals;
} Map;

Map *new_map();
void map_put(Map *map, char *key, void *val);
void *map_get(Map *map, char *key);
void test_map();

