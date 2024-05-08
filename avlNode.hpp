template <class T>
class AVLNode
{
public:
    AVLNode *left, *right;
    T key;
    AVLNode();
    AVLNode(const T &el, AVLNode *l = 0, AVLNode *r = 0);
};