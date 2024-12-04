#pragma once

struct dvec {
  int n;
  int *data;
};

// Fonctions pour allouer et libérer la structure
void dvec_init(struct dvec *v, int n);
void dvec_free(struct dvec *v);
bool dvec_ok(struct dvec *v);
void dvec_dump(struct dvec *v);

// Fonctions de diffusion
void dvec_bcast_lib(struct dvec *v);
void dvec_bcast_seq(struct dvec *v);

