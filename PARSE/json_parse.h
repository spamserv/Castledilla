/*
 * json_parse.h
 *
 *  Created on: Dec 5, 2016
 *      Author: rtrk
 */

static int jsoneq(const char *json, jsmntok_t *tok, const char *s);
void json_to_struct(PLAYER* player, char* JSON_STRING);
