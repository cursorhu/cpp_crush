#include "shoes.hpp"

int main()
{
    // 构造工厂对象
    ShoesFactory shoesFactory;

    // 从鞋工厂对象创建阿迪达斯鞋对象
    auto pNikeShoes = shoesFactory.CreateShoes(NIKE);
    if (pNikeShoes != NULL)
    {
        // 耐克球鞋广告喊起
        pNikeShoes->Show();
    }

    // 从鞋工厂对象创建阿迪达斯鞋对象
    auto pLiNingShoes = shoesFactory.CreateShoes(LINING);
    if (pLiNingShoes != NULL)
    {
        // 李宁球鞋广告喊起
        pLiNingShoes->Show();
    }

    // 从鞋工厂对象创建阿迪达斯鞋对象
    auto pAdidasShoes = shoesFactory.CreateShoes(ADIDAS);
    if (pAdidasShoes != NULL)
    {
        // 阿迪达斯球鞋广告喊起
        pAdidasShoes->Show();
    }

    return 0;
    //unique_ptr是分配在栈上，此处 main return，指针销毁，其管理的堆上分配的对象也自动释放
}