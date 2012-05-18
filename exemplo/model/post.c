/*
 * post.c
 *
 * License: FreeBSD
 */
#include <exemplo.h>
#include <mysql.h>

MYSQL_RES *ModelPost_GetPosts()
{
	return Query("SELECT * FROM post");
}
