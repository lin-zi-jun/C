   执行命令 ``protoc-c --c_out=. user.proto`` 后将生成user.pb-c.c、user.pb-c.h两个文件，编译的时候需要加上 -lprotobuf-c 选项。

    简单看下生成的文件接口，主要就是：

    结构体： struct  _User 

    相关接口：user__init、user__pack、user__unpack、user__free_unpacked

安装protobuf_c
https://www.jianshu.com/p/ad986d6e4401
