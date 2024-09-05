#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char* dyn_strcpy(char *dest, const char *src)
{
	dest = (char*)realloc(dest,strlen(src) + 1);
	if(dest == NULL)
	{
		printf("Meory reallocation failed\n");
		free(dest);	
		exit(1);
	}
	char* tmp = dest;
	const char* tmp1 = src;
	while(*src)
	{
		*tmp = *src;
		tmp++;
		src++;	
	}

	*tmp = '\0';
	src = tmp1;
	return dest;
}

char* dyn_strncpy(char *dest, const char *src, size_t n)
{
	dest = (char*)realloc(dest,strlen(src) + 1);
	if(dest == NULL)
	{
		printf("Memory reallocation failed\n");
		free(dest);
		exit(1);
	}
	char* tmp = dest;
	const char* tmp1 = src;
	while(*src && n)
	{
		*tmp = *src;
		tmp++;
		src++;
		n--;	
	}

	*tmp = '\0';
	src = tmp1;
	return dest;

}

char* dyn_strcat(char *dest, const char *src)
{
	int dest_size = strlen(dest) - 1;
	int need_size = strlen(dest) + strlen(src) + 1;
	dest = (char*)realloc(dest,need_size);
	const char* tmp = src;
	if(dest == NULL)
	{
		printf("Memory reallocation failed\n");
		free(dest);
		exit(1);
	}
	while(*src)
	{
		dest[dest_size++] = *src;
		src++;
	}

	dest[dest_size] = 0;
	
	src = tmp;
	return dest;
	
}

char* dyn_strncat(char *dest, const char *src, size_t n)
{
	int dest_size = strlen(dest) - 1;
	int need_size = strlen(dest) + strlen(src) + 1;
	dest = (char*)realloc(dest,need_size);
	const char* tmp = src;
	if(dest == NULL)
	{
		printf("Memory reallocation failed\n");
		free(dest);
		exit(1);
	}

	while(*src && n)
	{
		dest[dest_size++] = *src;
		src++;
		n--;
	}

	dest[dest_size] = 0;
	src = tmp;

	return dest;
	
}


int dyn_strcmp(const char *str1, const char *str2)
{
	while(*str1 && *str2)
	{
		if(*str1 > *str2)
			return 1;
		else if(*str1 < *str2)
			return -1;
		
		str1++;
		str2++;
		
	}


	if(*str1 == '\0' && *str2 != '\0')
		return -1;
	else if(*str1 != '\0' && *str2 == '\0')
		return 1;

	return 0;
	
}

//int dyn_strncmp(const char *str1, const char *str2, size_t n)


/*
{
	const char* tmp1 = str1;
	const char* tmp2 = str2;
	while(*str1 && *str2 && n)
	{
		if(*str1 > *str2)
		{	
			str1 = tmp1;
			str2 = tmp2;
			return 1;
		}
		else if(*str1 < *str2)
		{
			str1 = tmp1;
			str2 = tmp2;
			return -1;
		}
		str1++;
		str2++;
		n--;
		
	}


	if(*str1 == '\0' && *str2 != '\0')
	{
		str1 = tmp1;
		str2 = tmp2;
		return -1;
	}
	else if(*str1 != '\0' && *str2 == '\0')
	{
		str1 = tmp1;
		str2 = tmp2;
		return 1;
	}

	str1 = tmp1;
	str2 = tmp2;
	return 0;
}
*/

int dyn_strncmp(const char *str1, const char *str2, size_t n) {
    while (n && *str1 && *str2 && (*str1 == *str2)) {
        str1++;
        str2++;
        n--;
    }

    if (n == 0) {
        return 0;
    }

    if (!*str1 && *str2) {
        return -1;
    } else if (*str1 && !*str2) {
        return 1;
    } else if (*str1 && *str2) {
        return (*str1 > *str2) ? 1 : -1;
    }

    return 0;
}
size_t dyn_strlen(const char *str)
{
	const char* tmp = str;
	while(*tmp)
	{
		tmp++;
	}
	
	return tmp - str;
}

char* dyn_strchr(const char *str, int c)
{
	const char* tmp = str;
	while(*str)
	{
		if(*str == (char)c)
		{
			return (char*)str;
		}

		str++;
	}
	str = tmp;
	return 	NULL;
}

char* dyn_strrchr(const char *str, int c)
{
	int len = strlen(str);
	const char* tmp = str;
	while(len)
	{
		if(*str == (char)c);
		{
			return (char*)str;
		}
	}
	
}
char* dyn_strstr(const char *str1, const char *str2)
{
	int n = dyn_strlen(str2);
	
	while(*str1)
	{
		if(*str1 == *str2)
		{
			if(dyn_strncmp(str1,str2,n) == 0)
			{
				return (char*)str1;
			}
		}

	str1++;
		
	}

	return NULL;
}

