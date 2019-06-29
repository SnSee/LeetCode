/* 二叉堆基本操作 */

/* 上浮叶节点(二叉堆插入一个新节点后调用) */
void upNode(int *array, int arraySize){
    int childIndex = arraySize - 1;
    int parentIndex = (childIndex - 1) / 2;
    int temp = array[childIndex];
    while(childIndex > 0 && temp < array[parentIndex]){
        array[childIndex] = array[parentIndex];
        childIndex = parentIndex;
        parentIndex = (parentIndex - 1) / 2;
    }
    array[childIndex] = temp;
}
/* 将当前父节点下沉到能下沉的最深位置(最小二叉堆) */
void downNode(int *array, int arraySize, int parentIndex){
    // 保存父节点的值
    int temp = array[parentIndex];
    int childIndex = 2 * parentIndex + 1;
    while(childIndex < arraySize){
        // 如果有右子节点且右子节点的值小于左子节点的值，则定位到右子节点
        if(childIndex + 1 < arraySize && array[childIndex + 1] < array[childIndex]){
            ++childIndex;
        }
        // 如果父节点比最小的子节点还小，跳出循环
        if(temp <= array[childIndex]){
            break;
        }
        // 如果未跳出循环，单向赋值
        array[parentIndex] = array[childIndex];
        // 继续下沉
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;
    }
    // 将最终下沉的位置设为初始父节点的值
    array[parentIndex] = temp;
}
/* 将一个普通二叉树转换成二叉堆 */
void buildBinaryHeap(int *array, int arraySize){
    // 从最后一个非叶节点开始，依次下沉父节点（如果需要下沉）
    for(int i = (arraySize-2)/2; i >= 0; --i){
        downNode(array, arraySize, i);
    }
}


/* 广度优先遍历二叉树 */
void printBinaryTree(int *array, int arraySize){
    
}