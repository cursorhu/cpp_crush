# cpp_crush

C++ 各个击破  

## 基本方法：
    
```flow
s=>start: 输入
o1=>operation: 内化
o2=>operation: 反馈
c1=>condition: 实践
e=>end: 输出

s(right)->o1()->c1
c1(yes, right)->e
c1(no)->o2(left)->o1
```


1. 知识输入：以书和项目，系统的学习语法，惯例，原理   
2. 知识内化：关键知识点，手写代码验证，写key-point笔记  
3. 知识反馈和输出：在实践中检验，根据反馈修正内化的知识点，以输出强化内化效果    

## 基础语法和原理   
1. C++ primer 4th (Done)  
2. effective C++ 3rd (Done)  
3. modern C++ 11/14/17/20 (Done)   
4. 深度探索C++对象模型 (TODO)  

## 应用惯例  
1. 设计模式 (TODO)  
2. 资源管理：内存泄漏，智能指针，线程池，内存池 (TODO)  
3. STL和boost (TODO)  

## 特定领域  
1. GUI: QT & MFC (TODO)
2. 网络服务：同步异步方式 (TODO)
3. 基础库：rpc (TODO)