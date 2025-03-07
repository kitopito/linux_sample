
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char *pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	//
	int ret = chdir("../linux_sample/../../././cursus/../cursus/linux_sample");
	printf("%d\n", ret);
	pwd = getcwd(NULL, 0);
	printf("getcwd %s\n", pwd);
	printf("getenv %s\n", getenv("PWD"));
	free(pwd);
	//
	ret = chdir("./chdir_err.c");
	perror(NULL);
	pwd = getcwd(NULL, 0);
	printf("getcwd %s\n", pwd);
	printf("getenv %s\n", getenv("PWD"));
	free(pwd);
	//
	ret = chdir(".");
	printf("%d\n", ret);
	pwd = getcwd(NULL, 0);
	printf("getcwd %s\n", pwd);
	printf("getenv %s\n", getenv("PWD"));
	free(pwd);
	//
	ret = chdir("..");
	printf("%d\n", ret);
	pwd = getcwd(NULL, 0);
	printf("getcwd %s\n", pwd);
	printf("getenv %s\n", getenv("PWD"));
	free(pwd);
	//
	ret = chdir("~/cursus/linux_sample");
	printf("%d\n", ret);
	pwd = getcwd(NULL, 0);
	printf("getcwd %s\n", pwd);
	printf("getenv %s\n", getenv("PWD"));
	free(pwd);
	//
	ret = chdir("");
	printf("%d\n", ret);
	pwd = getcwd(NULL, 0);
	printf("getcwd %s\n", pwd);
	printf("getenv %s\n", getenv("PWD"));
	free(pwd);
	return (0);
}