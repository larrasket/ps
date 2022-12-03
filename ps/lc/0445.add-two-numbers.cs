public
class Solution {
private
  void ListToStack(ListNode head, Stack<ListNode> stack) {
    var curr = head;
    while (curr != null) {
      stack.Push(curr);
      curr = curr.next;
    }
  }

public
  ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
    Stack<ListNode> l1Stack = new Stack<ListNode>();
    Stack<ListNode> l2Stack = new Stack<ListNode>();
    Stack<ListNode> resStack = new Stack<ListNode>();

    ListToStack(l1, l1Stack);
    ListToStack(l2, l2Stack);

    int carry = 0;

    while (l1Stack.Count > 0 || l2Stack.Count > 0) {
      var digit1 = (l1Stack.Count > 0 ? l1Stack.Pop().val : 0);
      var digit2 = (l2Stack.Count > 0 ? l2Stack.Pop().val : 0);
      int sum = digit1 + digit2 + carry;
      int currentDigit = sum % 10;
      carry = sum / 10;

      resStack.Push(new ListNode(currentDigit));
    }

    if (carry != 0) {
      resStack.Push(new ListNode(carry));
    }

    if (resStack.Count == 0) {
      return null;
    }

    var res = resStack.Pop();
    var last = res;

    while (resStack.Count > 0) {
      last.next = resStack.Pop();
      last = last.next;
    }

    return res;
  }
}
