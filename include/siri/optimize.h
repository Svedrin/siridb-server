/*
 * optimize.h - Optimize task SiriDB.
 *
 * author       : Jeroen van der Heijden
 * email        : jeroen@transceptor.technology
 * copyright    : 2016, Transceptor Technology
 *
 * changes
 *  - initial version, 09-05-2016
 *
 */
#ifndef SIRI_OPTIMIZE_H_
#define SIRI_OPTIMIZE_H_

#define SIRI_OPTIMIZE_PENDING 0
#define SIRI_OPTIMIZE_RUNNING 1
#define SIRI_OPTIMIZE_CANCELLED 2
#define SIRI_OPTIMIZE_PAUSED 3  /* only set in 'siri_optimize_wait' */
#define SIRI_OPTIMIZE_PAUSED_MAIN 4

typedef struct siri_optimize_s siri_optimize_t;

#define SIRI_OPTIMZE_IS_PAUSED (siri.optimize->status >= SIRI_OPTIMIZE_PAUSED)

#include <uv.h>
#include <stdio.h>
#include <siri/siri.h>

void siri_optimize_init(siri_t * siri);
void siri_optimize_stop(void);
void siri_optimize_pause(void);
void siri_optimize_continue(void);
int siri_optimize_wait(void);
int siri_optimize_create_idx(const char * fn);
int siri_optimize_finish_idx(const char * fn, int remove_old);

struct siri_optimize_s
{
    uv_timer_t timer;
    int status;
    time_t start;
    uv_work_t work;
    uint16_t pause;
    FILE * idx_fp;
    char * idx_fn;
};
#endif  /* SIRI_OPTIMIZE_H_ */
