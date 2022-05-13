bool CalcPostorder(const int* preorder,const int* inorder,int* postorder,int lenth){
    
    int preB=0;
    int preE=lenth-1;
    int inB=0;
    int inE=lenth-1;
    postorder=​traversal(preorder,preB,preE,inorder,inB,E);

    //根据后序遍历结果反推前序和中序遍历，看是否自相矛盾
    bool pre=judepre(postorder);
    bool inoder=judeInoder(postder);    
    if(pre&&inoder)   return true;
    else return false;​
}
TreeNode* traversal(const int* preorder,int preB,int preE,const int* inorder,int inB,int E){
    int rootValue=preorder[preB];
    TreeNode* root=new TreeNode(rootValue);
    if(preE-preB==1) return true;

    int index;
    for(index=inB;lindex<inE;index++){
        if(inordered[index]==rootValue) break;
    }

    int leftInB=inB;
    int leftInE=index;
    
    int rightB=index+1;
    int rightE=inE;

    int leftPreB=preB+1;
    int leftPreE=preB+(index-inB)+1;

    int rightPreB=preB+(index-inB)+1;
    int rightPreE=preE;

    root->left=traversal(preorder,inorder,postorder,length);
    root->right=traversal(preorder,inorder,postorder,length);

    return root;​
}