class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        TreeNode cur = root;
        if(root == null){
            return list;
        }
        TreeNode flag = null;
        Stack<TreeNode> stack = new Stack<>();
        while(cur != null || !stack.isEmpty()){
            while(cur != null){
                stack.push(cur);
                cur = cur.left;
            }
            //由于根还在栈中，为了防止一直循环，需要对访问过的进行标记
            TreeNode node = stack.peek();
            if(node.right == null || node.right == flag){
                list.add(node.val);
                stack.pop();
                flag = node;
            }else{
                cur = node.right;
            }
        }
           return list;
    }
}
