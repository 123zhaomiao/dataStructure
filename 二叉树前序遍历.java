class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
       List<Integer> list = new ArrayList<>();
       if(root == null){
           return list;
       }
        Stack<TreeNode> stack = new Stack<>(); 
        TreeNode cur = root;
        stack.push(root);
        while(list.size() == 0 || !stack.isEmpty()){
           while(cur != null){
                stack.push(cur);
                list.add(cur.val);
                cur = cur.left;
            }
            TreeNode rightTree = stack.pop();
            cur = rightTree.right;
        }
        return list;
    }
}
