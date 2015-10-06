class MyQueue {
    private Stack s_in = new Stack();
    private Stack s_out = new Stack();
    // Push element x to the back of queue.
    public void push(int x) {
        s_in.push(new Integer(x));
    }

    // Removes the element from in front of queue.
    public void pop() {
        if (!s_out.empty()) {
            s_out.pop();
            return;
        }
        while (!s_in.empty()) {
            s_out.push(s_in.pop());
        }
        if (!s_out.empty()) {
            s_out.pop();
            return;
        }
    }

    // Get the front element.
    public int peek() {
        if (!s_out.empty()) {
            return (Integer)s_out.peek();
        }
        while (!s_in.empty()) {
            s_out.push(s_in.pop());
        }
        return (Integer)s_out.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return s_in.empty() && s_out.empty();
    }
}
