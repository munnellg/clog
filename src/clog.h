#ifndef __CLOG_H__
#define __CLOG_H__

#define CLOG_ERROR(...) do { \
    clog_message(CLOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__); \
} while (0)

#define CLOG_WARN(...) do { \
    clog_message(CLOG_LEVEL_WARN, __FILE__, __LINE__, __VA_ARGS__); \
} while (0)

#define CLOG_INFO(...) do { \
    clog_message(CLOG_LEVEL_INFO, __FILE__, __LINE__, __VA_ARGS__); \
} while (0)

#define CLOG_DEBUG(...) do { \
    clog_message(CLOG_LEVEL_DEBUG, __FILE__, __LINE__, __VA_ARGS__); \
} while (0)

enum clog_level {
    CLOG_LEVEL_OFF,   /* disable logging */
    CLOG_LEVEL_ERROR, /* log only error messages */
    CLOG_LEVEL_WARN,  /* log warnings and errors */
    CLOG_LEVEL_INFO,  /* log warnings, errors and info messages */
    CLOG_LEVEL_DEBUG  /* log all messages including debug messages */
};

enum clog_echo {
    CLOG_ECHO_OFF, /* disable echoing to stderr */
    CLOG_ECHO_ON   /* enable echoing to stderr */
};

void clog_init(enum clog_level level, enum clog_echo echo);

int clog_open(const char *fname);

void clog_set_echo(enum clog_echo echo);

void clog_set_level(enum clog_level level);

void clog_close(void);

void clog_message (enum clog_level level, const char *file, int line,
    const char *msg, ...);

#endif
