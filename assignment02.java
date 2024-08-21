/**
 * assignment02
 */
public class assignment02 {

    public static void main(String[] args) {
        Stack stack = new Stack();

        stack.push(0);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);

        System.out.print("peek element is:");
        stack.peek();

        int popedElement = stack.pop();
        System.out.println("removed the Top element" + " " + popedElement);
        int peekElement = stack.peek();
        System.out.println("Peek element is :" + " " + peekElement);

        System.out.println("printing all elements");
        stack.display();
    }
}

class Node {
    int Data;
    Node next;

    Node(int new_data) {
        this.Data = new_data;
        this.next = null;
    }
}

class Stack {
    Node head;

    Stack() {
        this.head = null;
    }

    boolean isEmpty() {
        return head == null;
    }

    void push(int new_data) {
        Node newNode = new Node(new_data);

        if (newNode == null) {
            System.out.println("\nStack overflow");
            return;
        }
        newNode.next = head;
        head = newNode;

    }

    int pop() {
        if (isEmpty()) {
            System.out.println("\nStavk underflow");
            return -1;
        } else {
            Node temp = head;
            head = head.next;
            // temp = null;
            return temp.Data;
        }
    }

    int peek() {
        if (isEmpty()) {
            System.out.println("\nStavk underflow");
            return -1;
        } else {
            return head.Data;
        }
    }

    void display() {
        Node temp = head;

        while (temp != null) {
            System.out.print(temp.Data + "->");
            temp = temp.next;
        }
        System.out.println();
    }

}