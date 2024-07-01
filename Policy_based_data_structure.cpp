#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace __gnu_pbds;
typedef tree<
    int,
    null_type,
    std::less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

int main(){
    ordered_set s;
    s.insert(5);
    s.insert(1);
    s.insert(3);
    std::cout << *s.find_by_order(3) << std::endl;
    return 0;
}