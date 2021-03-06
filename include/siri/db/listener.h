/*
 * listener.h - contains functions for processing queries.
 *
 * author       : Jeroen van der Heijden
 * email        : jeroen@transceptor.technology
 * copyright    : 2016, Transceptor Technology
 *
 * changes
 *  - initial version, 10-03-2016
 *
 */
#ifndef SIRIDB_LISTENER_H_
#define SIRIDB_LISTENER_H_

#include <uv.h>
#include <siri/grammar/grammar.h>

uv_async_cb siridb_listen_enter[CLERI_END];
uv_async_cb siridb_listen_exit[CLERI_END];

void siridb_init_listener(void);

#endif  /* SIRIDB_LISTENER_H_ */
