#include "rumcc.h"

Node *code[100];

void program() {
    int i = 0;
    while (tokens[pos].ty != TK_EOF)
        code[i++] = stmt();
    code[i] = NULL;
}

Node *stmt() {
    Node *node assign();
    if (!consume(';'))
        error("';'ではないトークンです: %s", tokens[pos].input);
}

Node *add() {
    Node *node = mul();

    for (;;) {
        if (consume('+'))
            node = new_node('+', node, mul());
        else if (consume('-'))
            node = new_node('-', node, mul());
        else
            return node;
    }
}

Node *mul() {
  Node *node = term();

  for (;;) {
    if (consume('*'))
      node = new_node('*', node, term());
    else if (consume('/'))
      node = new_node('/', node, term());
    else
      return node;
  }
}

Node *term() {
    if (consume('(')) {
        Node *node = add();
        if (!(consume(')')))
            error('no right paren: %s', tokens[pos].input);
        return node;
    }

    if (tokens[pos].ty == TK_NUM)
        return new_node_num(tokens[pos++].val);

    error('not term token: %s', tokens[pos].input);
}

