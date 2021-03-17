#include <stdio.h>
#include"user.pb-c.h"


#define FAILURE -1
#define SUCCESS 0


static size_t __do_pack(unsigned char  *buffer)
{
        User user;
 
        user__init(&user);
 
        user.name   = "zhangsan";
        user.phone  = "010-1234-5678";
        user.email  = "zhangsan@123.com";
        user.stat   = USER__STATUS__IDLE;
 
        return user__pack(&user, buffer);
}

static int __do_unpack(const unsigned char  *buffer, size_t len)
{
        User *pusr = user__unpack(NULL, len, buffer);
        if (!pusr) {
                printf("user__unpack failed\n");
                return FAILURE;
        }
 
        // assert(pusr->magic == MAGIC);
        // assert(pusr->version == VERSION);
        printf("Unpack: %s %s %s\n", pusr->name, pusr->phone, pusr->email);
 
        user__free_unpacked(pusr, NULL);
        return SUCCESS;
}

int main(int argc, char *argv[])
{
        unsigned char  buffer[1024] = {0}; 
        size_t size = __do_pack(buffer);
        printf("Packet size: %zd\n", size);
        __do_unpack(buffer, size);
 
        exit(SUCCESS);
}
