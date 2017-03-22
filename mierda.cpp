/*
 * mierda.c
 *
 *  Created on: 21/03/2017
 *      Author: ernesto
 */

/*
 Node is defined as

 typedef struct node
 {
 int data;
 node * left;
 node * right;
 }node;

 */

#include <stdio.h>

typedef struct node {
	int data;
	node * left;
	node * right;
} node;

node * lca(node * root, int v1, int v2) {
	node *nodo_act = root;

	while (nodo_act) {
		bool se_encontro_1 = false;
		bool se_encontro_2 = false;
		node *nodo_act_1 = NULL;
		node *nodo_act_2 = NULL;
		if (v1 < nodo_act->data) {
			nodo_act_1 = nodo_act->left;
		} else {
			if (v1 > nodo_act->data) {
				nodo_act_1 = nodo_act->right;
			} else {
				se_encontro_1 = true;
			}
		}

		if (v2 < nodo_act->data) {
			nodo_act_2 = nodo_act->left;
		} else {
			if (v2 > nodo_act->data) {
				nodo_act_2 = nodo_act->right;
			} else {
				se_encontro_2 = true;
			}
		}

		if (se_encontro_1 && se_encontro_2) {
			break;
		}
		if (nodo_act_1 != nodo_act_2) {
			break;
		}

		nodo_act = nodo_act_1;
	}
	return nodo_act;
}
