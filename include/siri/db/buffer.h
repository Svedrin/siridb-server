/*
 * buffer.h - Buffer for integer and double series.
 *
 * author       : Jeroen van der Heijden
 * email        : jeroen@transceptor.technology
 * copyright    : 2016, Transceptor Technology
 *
 * changes
 *  - initial version, 01-04-2016
 *
 */
#pragma once

#include <siri/db/db.h>
#include <siri/db/series.h>
#include <siri/db/points.h>

typedef struct siridb_s siridb_t;
typedef struct siridb_series_s siridb_series_t;
typedef struct siridb_points_s siridb_points_t;

typedef struct siridb_buffer_s
{
    long int bf_offset;
    siridb_points_t * points;
} siridb_buffer_t;

int siridb_buffer_new_series(
        siridb_t * siridb,
        siridb_series_t * series);

int siridb_buffer_open(siridb_t * siridb);

int siridb_load_buffer(siridb_t * siridb);

void siridb_free_buffer(siridb_buffer_t * buffer);

void siridb_buffer_write_len(
        siridb_t * siridb,
        siridb_series_t * series);

/* Waring: we must check if the new point fits inside the buffer before using
 * the 'siridb_buffer_write_point()' function.
 */
void siridb_buffer_write_point(
        siridb_t * siridb,
        siridb_series_t * series,
        uint64_t * ts,
        qp_via_t * val);

void siridb_buffer_to_shards(
        siridb_t * siridb,
        siridb_series_t * series);