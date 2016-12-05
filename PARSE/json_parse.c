/*
 * json_parse.c
 *
 *  Created on: Dec 5, 2016
 *      Author: rtrk
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jsmn.h"
#include "../STRUCTURES/player.h"

/*
 * A small example of jsmn parsing when JSON structure is known and number of
 * tokens is predictable.
 */

/*static const char *JSON_STRING =
		"{\"player1\":{\"castle\":\"40\",\"fence\":\"10\",\"brick\":\"5\",\"crystal\":\"5\",\"weapon\":\"5\",\"schoolar\":\"1\",\"mage\":\"1\",\"soldier\":\"1\"},\"player2\":{\"castle\":\"40\",\"fence\":\"10\",\"brick\":\"5\",\"crystal\":\"5\",\"weapon\":\"5\",\"schoolar\":\"1\",\"mage\":\"1\",\"soldier\":\"1\"}}";*/

static int jsoneq(const char *json, jsmntok_t *tok, const char *s) {
	if (tok->type == JSMN_STRING && (int) strlen(s) == tok->end - tok->start &&
			strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
		return 0;
	}
	return -1;
}

void json_to_struct(PLAYER* player, char* JSON_STRING)
{
	PLAYER *modified_player = (PLAYER*) malloc(sizeof(PLAYER));
	int i;
	int r;
	jsmn_parser p;
	jsmntok_t t[128]; /* We expect no more than 128 tokens */

	jsmn_init(&p);
	r = jsmn_parse(&p, JSON_STRING, strlen(JSON_STRING), t, sizeof(t)/sizeof(t[0]));
	if (r < 0) {
		printf("Failed to parse JSON: %d\n", r);
	}

	/* Assume the top-level element is an object */
	if (r < 1 || t[0].type != JSMN_OBJECT) {
		printf("Object expected\n");
	}

	/* Loop over all keys of the root object */
	for (i = 1; i < r; i++) {
		if (jsoneq(JSON_STRING, &t[i], "player1") == 0) {
			/* We may use strndup() to fetch string value */
			printf("- player1: %.*s\n", t[i+1].end-t[i+1].start,
					JSON_STRING + t[i+1].start);
			i++;
		} else if (jsoneq(JSON_STRING, &t[i], "player2") == 0) {
			/* We may additionally check if the value is either "true" or "false" */
			printf("- player2: %.*s\n", t[i+1].end-t[i+1].start,
					JSON_STRING + t[i+1].start);
			i++;
		} else  {
			/* We may want to do strtol() here to get numeric value */
			printf(" %.*s\n", t[i+1].end-t[i+1].start,
					JSON_STRING + t[i+1].start);
			i++;
		}
	}
}

