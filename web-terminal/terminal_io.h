#pragma once
#ifdef __cplusplus
extern "C" {
#endif
int terminal_read_key(int timeout);
int terminal_key_count(void);
#ifdef __cplusplus
}
#endif
