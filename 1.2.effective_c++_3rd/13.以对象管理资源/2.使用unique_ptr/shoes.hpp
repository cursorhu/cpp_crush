
#include <iostream>
#include <memory> //smart pointer

// 鞋子抽象类
class Shoes
{
public:
    virtual ~Shoes() {}
    virtual void Show() = 0;
};

// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "NiKe: Just do it" << std::endl;
    }
    ~NiKeShoes()
    {
        std::cout << "~NiKeShoes" << std::endl;
    }
};

// 阿迪达斯鞋子
class AdidasShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "Adidas: Impossible is nothing" << std::endl;
    }
    ~AdidasShoes()
    {
        std::cout << "~AdidasShoes" << std::endl;
    }
};

// 李宁鞋子
class LiNingShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "LiNing: Everything is possible" << std::endl;
    }
    ~LiNingShoes()
    {
        std::cout << "~LiNingShoes" << std::endl;
    }
};

enum SHOES_TYPE
{
    NIKE,
    LINING,
    ADIDAS
};

// 总鞋厂
class ShoesFactory
{
public:
    // 根据鞋子类型创建对应的鞋子对象
    std::unique_ptr<Shoes> CreateShoes(SHOES_TYPE type)
    {
        switch (type)
        {
        case NIKE:
            return std::make_unique<NiKeShoes>();
            break;
        case LINING:
            return std::make_unique<AdidasShoes>();
            break;
        case ADIDAS:
            return std::make_unique<LiNingShoes>();
            break;
        default:
            return NULL;
            break;
        }
    }
};
