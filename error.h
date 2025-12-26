#ifndef ERROR_H
#define ERROR_H

int	err_msgReturnOne(const char *err_msg);

void	err_writeStdErr(const char *first_err_msg, int n_msg, ...);

#endif
