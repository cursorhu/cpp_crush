#include <vector>
#include <string>

using namespace std;

int main(){
    /* empty vector object */
    vector<int> ivec1;
    /* 10 element, each initialized to default 0 */
    vector<int> ivec2(10);
    /* 10 element, each initialized to 1 */
    vector<int> ivec3(10, 1);
    /* copy initialization */
    vector<int> ivec4(ivec2);
    /* all class/type can be element of vector */
    vector<string> svec1(10, "0");
    /* an vector in vector: 10 vector * each vector's 10 int elements */
    vector< vector<int> > ivec5(10, vector<int>(10));
}