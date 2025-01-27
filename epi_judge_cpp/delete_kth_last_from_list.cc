#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;

// Assumes L has at least k nodes, deletes the k-th last node in L.
shared_ptr<ListNode<int>> RemoveKthLast(const shared_ptr<ListNode<int>>& L,
                                        int k) {
  // TODO - you fill in here.
  auto k_forward = L, cur = L;
  while(--k)
      k_forward = k_forward->next;
  if(k_forward->next == nullptr)
      return L->next;
  k_forward = k_forward->next;
  while(k_forward->next)
  {
      cur = cur->next;
      k_forward = k_forward->next;
  }
  cur->next = cur->next->next;
  return L;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "k"};
  return GenericTestMain(args, "delete_kth_last_from_list.cc",
                         "delete_kth_last_from_list.tsv", &RemoveKthLast,
                         DefaultComparator{}, param_names);
}
