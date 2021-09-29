# Two Sum
## 题目
Given an array of integers, return indices of the two numbers such that they add up to a specific
target.

You may assume that each input would have exactly one solution, and you may not use the same
element twice.

### Example
```c++
Give nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]
```
## 题目大意
在数组中找到 2 个数之和等于给定值的数字，结果返回 2 个数字在数组中的下标。
## 解题思路
这道题最有的做法时间复杂度是O(n)。
顺序扫描数组，对每⼀个元素，在 map 中找能组合给定值的另⼀半数字，如果找到了，直接返回 2 个
数字的下标即可。如果找不到，就把这个数字存⼊ map 中，等待扫到“另⼀半”数字的时候，再取出来返
回结果。

本题中，遍历```nums```中的每一个数字<i,num>，求target-num值，并将这个值作为key到map中区找，如果存在，则返回map[key]对应的value及nums中的index，如果没找到，则在map中插入<num, i>
### 数据结构
```c++
std::map<T1, T2> 
```

Map是c++的一个标准容器，她提供了很好一对一的关系，在一些程序中建立一个map可以起到事半功倍的效果，总结了一些map基本简单实用的操作！  
1. map最基本的构造函数；
```c  
   map<string , int >mapstring;      map<int ,string >mapint;  
   map<sring, char>mapstring;        map< char ,string>mapchar;  
   map<char ,int>mapchar;            map<int ,char >mapint；
```
2. map添加数据；
```c++
   map<int ,string> maplive;
```
1.insert(std::pair<T1, T2>(key, value));
```c++    
   maplive.insert(pair<int,string>(102,"aclive"));
```  
2.insert(std::map<T1, T2>::value\_type(key, value));
```c++
   maplive.insert(map<int,string>::value\_type(321,"hai"));  
```
3.map[key]=value **特别注意，这种情况，如果map中不存在这个key，则会把这组<key, value>加入到map中**，使用需要非常慎重
```c++   
	maplive\[112\]="April";//map中最简单的插入添加！慎用，如果不存在，会把新元素插入  
```
3，map中元素的查找：

   find()函数返回一个迭代器指向键值为key的元素，如果没找到就返回指向map尾部的迭代器。        
```c++
   map<int ,string >::iterator l_it;;   
   l_it=maplive.find(112);  
   if(l_it==maplive.end())  
     cout<<"we do not find 112"<<endl;  
   else cout<<"wo find 112"<<endl; 
``` 
4,map中元素的删除：  
   如果删除112；  
```C++
   map<int ,string >::iterator l_it;;  
   l_it=maplive.find(112);  
   if(l_it==maplive.end())  
     cout<<"we do not find 112"<<endl;  
   else  maplive.erase(l_it);  //delete 112;  
```
5,map中 swap的用法：  
  Map中的swap不是一个容器中的元素交换，而是两个容器交换；  
  For example：  
```c++
  #include <map>  
  #include <iostream>

  using namespace std;

  int main( )  
  {  
      map <int, int> m1, m2, m3;  
      map <int, int>::iterator m1\_Iter;

      m1.insert ( pair <int, int>  ( 1, 10 ) );  
      m1.insert ( pair <int, int>  ( 2, 20 ) );  
      m1.insert ( pair <int, int>  ( 3, 30 ) );  
      m2.insert ( pair <int, int>  ( 10, 100 ) );  
      m2.insert ( pair <int, int>  ( 20, 200 ) );  
      m3.insert ( pair <int, int>  ( 30, 300 ) );

   cout << "The original map m1 is:";  
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )  
      cout << " " << m1\_Iter->second;  
      cout   << "." << endl;

   // This is the member function version of swap  
   //m2 is said to be the argument map; m1 the target map  
   m1.swap( m2 );

   cout << "After swapping with m2, map m1 is:";  
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )  
      cout << " " << m1_Iter -> second;  
      cout  << "." << endl;  
   cout << "After swapping with m2, map m2 is:";  
   for ( m1_Iter = m2.begin( ); m1_Iter != m2.end( ); m1_Iter++ )  
      cout << " " << m1_Iter -> second;  
      cout  << "." << endl;  
   // This is the specialized template version of swap  
   swap( m1, m3 );

   cout << "After swapping with m3, map m1 is:";  
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )  
      cout << " " << m1_Iter -> second;  
      cout   << "." << endl;  
}
```
6.map的sort问题：  
  Map中的元素是自动按key升序排序,所以不能对map用sort函数：  
  For example： 
```c++ 
 #include <map>  
 #include <iostream>
 using namespace std;

 int main( )  
 {  
   map <int, int> m1;  
   map <int, int>::iterator m1\_Iter;

   m1.insert ( pair <int, int>  ( 1, 20 ) );  
   m1.insert ( pair <int, int>  ( 4, 40 ) );  
   m1.insert ( pair <int, int>  ( 3, 60 ) );  
   m1.insert ( pair <int, int>  ( 2, 50 ) );  
   m1.insert ( pair <int, int>  ( 6, 40 ) );  
   m1.insert ( pair <int, int>  ( 7, 30 ) );

   cout << "The original map m1 is:"<<endl;  
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )  
      cout <<  m1_Iter->first<<" "<<m1_Iter->second<<endl;   
}  
```
  The original map m1 is:  
```c++
  1 20  
  2 50  
  3 60  
  4 40  
  6 40  
  7 30  
  请按任意键继续. . .
```
7，   map的基本操作函数：  
      C++ Maps是一种关联式容器，包含“关键字/值”对  
```c++
      begin()          // 返回指向map头部的迭代器  
      clear(）         // 删除所有元素  
      count()          // 返回指定元素出现的次数  
      empty()          // 如果map为空则返回true  
      end()            // 返回指向map末尾的迭代器  
      equal_range()    // 返回特殊条目的迭代器对  
      erase()          // 删除一个元素  
      find()           // 查找一个元素  
      get_allocator()  // 返回map的配置器  
      insert()         // 插入元素  
      key_comp()       // 返回比较元素key的函数  
      lower_bound()    // 返回键值>=给定元素的第一个位置  
      max_size()       // 返回可以容纳的最大元素个数  
      rbegin()         // 返回一个指向map尾部的逆向迭代器  
      rend()           // 返回一个指向map头部的逆向迭代器  
      size()           // 返回map中元素的个数  
      swap()           // 交换两个map  
      upper_bound()    // 返回键值>给定元素的第一个位置  
      value_comp()     // 返回比较元素value的函数
```
 **8、iterator是否为空的判断**

对于容器而言,是判断是否为```end()```;对于sring而言,是判断是否是```string::npos```,但是如果是针对string的话,就不是"iterator",而是一般的整型值而已

**9、iterator的初始化----用end()**
```c++
list<char*>  list;
list<char*>::iterator it=slist.end();  
```

\---------------------------------------------------------------

**map详解：**

Map是STL的一个关联容器，它提供一对一（其中第一个可以称为关键字，每个关键字只能在map中出现一次，第二个可能称为该关键字的值）的数据处理能力，由于这个特性，它完成有可能在我们处理一对一数据的时候，在编程上提供快速通道。这里说下map内部数据的组织，map内部自建一颗红黑树(一种非严格意义上的平衡二叉树)，这颗树具有对数据自动排序的功能，所以在map内部所有的数据都是有序的，后边我们会见识到有序的好处。

下面举例说明什么是一对一的数据映射。比如一个班级中，每个学生的学号跟他的姓名就存在着一一映射的关系，这个模型用map可能轻易描述，很明显学号用int描述，姓名用字符串描述(本篇文章中不用char \*来描述字符串，而是采用STL中string来描述),下面给出map描述代码：

Map<int, string> mapStudent;

1.       map的构造函数

map共提供了6个构造函数，这块涉及到内存分配器这些东西，略过不表，在下面我们将接触到一些map的构造方法，这里要说下的就是，我们通常用如下方法构造一个map：

Map<int, string> mapStudent;

2.       数据的插入

在构造map容器后，我们就可以往里面插入数据了。这里讲三种插入数据的方法：

第一种：用insert函数插入pair数据，下面举例说明(以下代码虽然是随手写的，应该可以在VC和GCC下编译通过，大家可以运行下看什么效果，在VC下请加入这条语句，屏蔽4786警告  ＃pragma warning (disable:4786) )
```c++
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
  Map<int, string> mapStudent;
  mapStudent.insert(pair<int, string>(1, "student_one"));
  mapStudent.insert(pair<int, string>(2, "student_two"));
  mapStudent.insert(pair<int, string>(3, "student_three"));
  map<int, string>::iterator  iter;
  for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++){
    cout<<iter->first<<"   "<<iter->second<<end;
  }
}
```
第二种：用insert函数插入value\_type数据，下面举例说明
```c++
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(){
  Map<int, string> mapStudent;
  mapStudent.insert(map<int, string>::value_type (1, "student\_one"));
  mapStudent.insert(map<int, string>::value_type (2, "student\_two"));
  mapStudent.insert(map<int, string>::value_type (3, "student\_three"));
  map<int, string>::iterator  iter;
  for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++){
       cout<<iter->first<<"   "<<iter->second<<end;
  }
}
```
**第三种：用数组方式插入数据，下面举例说明**
```c++
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(){
  Map<int, string> mapStudent;
  mapStudent[1] =  "student_one";
  mapStudent[2] =  "student_two";
  mapStudent[3] =  "student_three";
  map<int, string>::iterator  iter;
  for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++){
    cout<<iter->first<<”   ”<<iter->second<<end;
  }
}
```
**以上三种用法，虽然都可以实现数据的插入，但是它们是有区别的，当然了第一种和第二种在效果上是完成一样的，用insert函数插入数据，在数据的插入上涉及到集合的唯一性这个概念，即当map中有这个关键字时，insert操作是插入数据不了的，但是用数组方式就不同了，它可以覆盖以前该关键字对应的值**用程序说明
```c++
mapStudent.insert(map<int, string>::value_type (1, “student_one”));
mapStudent.insert(map<int, string>::value_type (1, “student_two”));
```
上面这两条语句执行后，map中1这个关键字对应的值是“student_one”，第二条语句并没有生效，那么这就涉及到我们怎么知道insert语句是否插入成功的问题了，可以用pair来获得是否插入成功，程序如下
```c++
Pair<map<int, string>::iterator, bool> Insert_Pair;
Insert_Pair = mapStudent.insert(map<int, string>::value_type (1, “student_one”));
```
我们通过pair的第二个变量来知道是否插入成功，它的第一个变量返回的是一个map的迭代器，如果插入成功的话Insert_Pair.second应该是true的，否则为false。

下面给出完成代码，演示插入成功与否问题
```c++
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
  map<int, string> mapStudent;
  pair<map<int, string>::iterator, bool> Insert_Pair;
  Insert_Pair ＝ mapStudent.insert(pair<int, string>(1, "student_one"));
  if(Insert_Pair.second == true){
    cout<<"Insert Successfully"<<endl;
  }else{
    cout<<"Insert Failure"<<endl;
  }
  Insert_Pair ＝ mapStudent.insert(pair<int, string>(1, "student_two"));
  if(Insert_Pair.second == true){
    cout<<"Insert Successfully"<<endl;
  } else{
    cout<<"Insert Failure"<<endl;
  }
  map<int, string>::iterator iter;
  for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++){
    cout<<iter->first<<"   "<<iter->second<<end;
  }
}
```
大家可以用如下程序，看下用数组插入在数据覆盖上的效果
```c++
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
  map<int, string> mapStudent;
  mapStudent[1] = "student_one";
  mapStudent[1] = "student_two";
  mapStudent[2] = "student_three";
  map<int, string>::iterator iter;
  for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++){
    cout<<iter->first<<"   "<<iter->second<<end;
  }
}
```
3.map的大小
在往map里面插入了数据，我们怎么知道当前已经插入了多少数据呢，可以用size函数，用法如下：
```c++
int nSize = mapStudent.size();
```
4.数据的遍历
这里也提供三种方法，对map进行遍历
第一种：应用前向迭代器，上面举例程序中到处都是了，略过不表
第二种：应用反相迭代器，下面举例说明，要体会效果，请自个动手运行程序
```c++
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(){
  map<int, string> mapStudent;
  mapStudent.insert(pair<int, string>(1, "student_one"));											   
  mapStudent.insert(pair<int, string>(2, "student_two"));											   
  mapStudent.insert(pair<int, string>(3, "student_three"));
  map<int, string>::reverse_iterator  iter;
  for(iter = mapStudent.rbegin(); iter != mapStudent.rend(); iter++){
    cout<<iter->first<<"   "<<iter->second<<end;
  }
}
```
第三种：用数组方式，程序说明如下
```c++
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(){
  map<int, string> mapStudent;
  mapStudent.insert(pair<int, string>(1, "student_one"));
  mapStudent.insert(pair<int, string>(2, "student_two"));
  mapStudent.insert(pair<int, string>(3, "student_three"));
  int nSize = mapStudent.size()
  for(int nIndex = 1; nIndex <= nSize; nIndex++){
    cout << mapStudent[nIndex] << end;
  }
}
```
5.数据的查找（包括判定这个关键字是否在map中出现）
在这里我们将体会，map在数据插入时保证有序的好处。
要判定一个数据（关键字）是否在map中出现的方法比较多，这里标题虽然是数据的查找，在这里将穿插着大量的map基本用法。
这里给出三种数据查找方法
第一种：用count函数来判定关键字是否出现，其缺点是无法定位数据出现位置,由于map的特性，一对一的映射关系，就决定了count函数的返回值只有两个，要么是0，要么是1，出现的情况，当然是返回1了
第二种：用find函数来定位数据出现位置，它返回的一个迭代器，当数据出现时，它返回数据所在位置的迭代器，如果map中没有要查找的数据，它返回的迭代器等于end函数返回的迭代器，程序说明
```c++
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(){
  map<int, string> mapStudent;
  mapStudent.insert(pair<int, string>(1, "student_one"));
  mapStudent.insert(pair<int, string>(2, "student_two"));
  mapStudent.insert(pair<int, string>(3, "student_three"));
  map<int, string>::iterator iter;
  iter = mapStudent.find(1);
  if(iter != mapStudent.end()){
    cout<<”Find, the value is ”<<iter->second<<endl;
  }else{
    cout<<”Do not Find”<<endl;
  }
}

第三种：这个方法用来判定数据是否出现，是显得笨了点，但是，我打算在这里讲解
Lower_bound函数用法，这个函数用来返回要查找关键字的下界(是一个迭代器)
Upper_bound函数用法，这个函数用来返回要查找关键字的上界(是一个迭代器)
例如：map中已经插入了1，2，3，4的话，如果lower_bound(2)的话，返回的2，而upper-bound（2）的话，返回的就是3
Equal_range函数返回一个pair，pair里面第一个变量是Lower_bound返回的迭代器，pair里面第二个迭代器是Upper_bound返回的迭代器，如果这两个迭代器相等的话，则说明map中不出现这个关键字，程序说明
```c++
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(){
  map<int, string> mapStudent;
  mapStudent[1] = "student_one";
  mapStudent[3] = "student_three";
  mapStudent[5] = "student_five";
  map<int, string>::iterator  iter;
  iter = mapStudent.lower_bound(2);
  {
    //返回的是下界3的迭代器
    cout<<iter->second<<endl;
  }
  iter = mapStudent.lower_bound(3);
  {
    //返回的是下界3的迭代器
    cout<<iter->second<<endl;
  }
  iter = mapStudent.upper_bound(2);
  {
    //返回的是上界3的迭代器
    cout<<iter->second<<endl;
  }
  iter = mapStudent.upper_bound(3);
  {
    //返回的是上界5的迭代器
    cout<<iter->second<<endl;
  }

  pair<map<int, string>::iterator, map<int, string>::iterator> mapPair;
  mapPair = mapStudent.equal_range(2);
  if(mapPair.first == mapPair.second)  {
    cout<<"Do not Find"<<endl;
  }else{
    cout<<"Find"<<endl;  
  } 
  mapPair = mapStudent.equal_range(3);

  if(mapPair.first == mapPair.second)  {
    cout<<"Do not Find"<<endl;
  }else{
    cout<<"Find"<<endl;  
  }
}
```
6.数据的清空与判空

清空map中的数据可以用clear()函数，判定map中是否有数据可以用empty()函数，它返回true则说明是空map

7.数据的删除

这里要用到erase函数，它有三个重载了的函数，下面在例子中详细说明它们的用法
```c++
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(){
  map<int, string> mapStudent;
  mapStudent.insert(pair<int, string>(1,"student_one"));
  mapStudent.insert(pair<int, string>(2,"student_two"));
  mapStudent.insert(pair<int, string>(3,"student_three"));
  //如果你要演示输出效果，请选择以下的一种，你看到的效果会比较好
  //如果要删除1,用迭代器删除
  map<int, string>::iterator iter;
  iter = mapStudent.find(1);
  mapStudent.erase(iter);
  //如果要删除1，用关键字删除
  int n = mapStudent.erase(1);//如果删除了会返回1，否则返回0
  //用迭代器，成片的删除
  //一下代码把整个map清空
  mapStudent.earse(mapStudent.begin(), mapStudent.end());
  //成片删除要注意的是，也是STL的特性，删除区间是一个前闭后开的集合
  //自个加上遍历代码，打印输出吧
}
```
8.其他一些函数用法
这里有swap,key_comp,value_comp,get_allocator等函数，感觉到这些函数在编程用的不是很多，略过不表，有兴趣的话可以自个研究
9.排序
这里要讲的是一点比较高深的用法了,排序问题，STL中默认是采用小于号来排序的，以上代码在排序上是不存在任何问题的，因为上面的关键字是int型，它本身支持小于号运算，在一些特殊情况，比如关键字是一个结构体，涉及到排序就会出现问题，因为它没有小于号操作，insert等函数在编译的时候过不去，下面给出两个方法解决这个问题
第一种：小于号重载，程序举例
```c++
#include <map>
#include <string>
using namespace std;
typedef struct tagStudentInfo
{
  int      nID;
  string   strName;
  bool operator < (tagStudentInfo const& _A) const{
  //这个函数指定排序策略，按nID排序，如果nID相等的话，按strName排序
    if(nID < _A.nID)  return true;
    if(nID == _A.nID) return strName.compare(_A.strName) < 0;
    Return false;
  }
}StudentInfo, \*PStudentInfo;  //学生信息
int main(){
  int nSize;
  //用学生信息映射分数
  map<StudentInfo, int>mapStudent;
  map<StudentInfo, int>::iterator iter;
  StudentInfo studentInfo;
  studentInfo.nID = 1;
  studentInfo.strName = "student_one";
  mapStudent.insert(pair<StudentInfo, int>(studentInfo, 90));
  studentInfo.nID = 2;
  studentInfo.strName = "student_two";
  mapStudent.insert(pair<StudentInfo, int>(studentInfo, 80));
  for (iter=mapStudent.begin(); iter!=mapStudent.end(); iter++)
    cout<<iter->first.nID<<endl<<iter->first.strName<<endl<<iter->second<<endl;
}
```

第二种：仿函数的应用，这个时候结构体中没有直接的小于号重载，程序说明
```c++
#include <map>
#include <string>
using namespace std;
typedef struct tagStudentInfo{
  int      nID;
  string   strName;
}StudentInfo, \*PStudentInfo;  //学生信息

classs sort{
  public:
  bool operator() (StudentInfo const &_A, StudentInfo const &_B) const{
    if(_A.nID < _B.nID) return true;
    if(_A.nID == _B.nID) return _A.strName.compare(_B.strName) < 0;
    return false;
  }
};

int main(){
  //用学生信息映射分数
  map<StudentInfo, int, sort>mapStudent;
  StudentInfo studentInfo;
  studentInfo.nID = 1;
  studentInfo.strName = "student_one";
  mapStudent.insert(pair<StudentInfo, int>(studentInfo, 90));
  studentInfo.nID = 2;
  studentInfo.strName = "student_two";
  mapStudent.insert(pair<StudentInfo, int>(studentInfo, 80));
}
```
10.   另外

由于STL是一个统一的整体，```map```的很多用法都和STL中其它的东西结合在一起，比如在排序上，这里默认用的是小于号，即```less<>```，如果要从大到小排序呢，这里涉及到的东西很多，在此无法一一加以说明。

还要说明的是，```map```中由于它内部有序，由红黑树保证，因此很多函数执行的时间复杂度都是```log2N```的，如果用```map```函数可以实现的功能，而STL  Algorithm也可以完成该功能，建议用```map```自带函数，效率高一些。

下面说下，```ma```p在空间上的特性，否则，估计你用起来会有时候表现的比较郁闷，由于```map```的每个数据对应红黑树上的一个节点，这个节点在不保存你的数据时，是占用16个字节的，一个父节点指针，左右孩子指针，还有一个枚举值（标示红黑的，相当于平衡二叉树中的平衡因子），我想大家应该知道，这些地方很费内存了吧，不说了……

