#include"test.pb.h"   //头文件
#include<string.h>
#include<iostream>
using namespace mytest;   //作用域  偷懒了

int main()
{
    LogRequest req;    //定义我们的一个消息结构类
    req.set_name("jiler");
    req.set_pwd("55661xx1");
    //对象数据序列化-》string
    std::string send_str;     //保存到序列化后的字符串
    if(req.SerializeToString(&send_str))  //序列化
    {
        std::cout<<"序列化后的数据:"<<send_str<<std::endl;
    }

    //string反序列化 原本的对象数据
    LogRequest ans;
    if(ans.ParseFromString(send_str))  //反序列化
    {
        std::cout<<"反序列化后的数据:"<<ans.name()<<std::endl;
        std::cout<<"反序列化后的数据:"<<ans.pwd()<<std::endl;
    }

    std::cout<<"-----------"<<std::endl;

    GetUserFriendRep users;
    ErrCode* ers=users.mutable_errs();//获取对象指针
    ers->set_errcode(0);
    ers->set_errmsg("登录成功");

    //列表
    for(int i=0;i<3;++i)
    {
        Detail *usr=users.add_data();
        usr->set_id(i);
        usr->set_name("tom"+std::__cxx11::to_string(i));
        usr->set_age(20+i);
        if(i%2){
            usr->set_sex(Detail::MAN);
        }
        else{
            usr->set_sex(Detail::WOMAN);
        } 
    }
    std::cout<<users.data_size()<<std::endl; //返回几组数据 

    return 0;
}