// Don't have time to write a Tree class in C++ and worry about pointers, so use Java :O
// Using an AVL Tree with order statistics (for select)
// Using sqrt N decomposition for intervals 
// and processing queries offline, in sorted order
import java.io.*;
import java.util.*;

public class f {

    static int people[] = new int[10005];
    static class Q {
        int a, b, k, i;
        
        public Q() {}

        public Q(int a, int b, int k, int i) {
            this.a = a;
            this.b = b;
            this.k = k;
            this.i = i;
        }
    }

    static Node pool[];
    static int pool_index;
    static int pool_max;

    static class Node {
        int count, data, size, height;
        Node left, right;

        public Node() {}
        
        public static Node createAndInsert(int d) {
            Node tmp = pool[pool_index];
            tmp.count = 1;
            tmp.size = 1;
            tmp.height = 1;
            tmp.data = d;
            tmp.left = null;
            tmp.right = null;
            pool_index = (pool_index+1)%pool_max;
            return tmp;
        }

        public int getSizeLeft() {
            if (left == null) return 0;
            return left.size;
        }

        public int getSizeRight() {
            if (right== null) return 0;
            return right.size;
        }

        public void updateSize() {
            size = getSizeLeft() + count + getSizeRight();
        }

        public int getHeightLeft() {
            if (left==null) return 0;
            return left.height;
        }

        public int getHeightRight() {
            if (right==null) return 0;
            return right.height;
        }

        public void updateHeight() {
            height = Math.max(getHeightLeft(), getHeightRight()) + 1;
        }

        public void insertLeft(int d) {
            if (left==null)
                left = createAndInsert(d);
            else left.insert(d);
        }

        public void insertRight(int d) {
            if (right==null)
                right= createAndInsert(d);
            else right.insert(d);
        }

        public void insert(int d) {
            if (d==data)
                count++;
            else if (d<data)
                insertLeft(d);
            else
                insertRight(d);
            updateSize();
            updateHeight();
            if (left!=null)
                left.rebalance(this);
            if (right!=null)
                right.rebalance(this);
        }

        public void delete(int d) {
            if (d==data)
                count--;
            else if (d<data)
                left.delete(d);
            else 
                right.delete(d);
            updateSize();
            updateHeight();
        }

        public int select(int k) {
            int rSize = getSizeRight();
            if (k<=rSize) 
                return right.select(k);
            else if (rSize<k && k<=rSize+count)
                return data;
            else
                return left.select(k-rSize-count);
        }

        public void rotateRight(Node par) {
            Node tmpL = left;
            if (this == par.left)
                par.left = left;
            else
                par.right = left;
            left = left.right;
            tmpL.right= this;
            updateHeight();
            updateSize();
            tmpL.updateHeight();
            tmpL.updateSize();
        }

        public void rotateLeft(Node par) {
            Node tmpR = right;
            if (this == par.left)
                par.left = right;
            else
                par.right = right;
            right = right.left;
            tmpR.left = this;
            updateHeight();
            updateSize();
            tmpR.updateHeight();
            tmpR.updateSize();
        }

        public void rebalance(Node par) {
            int bal = getHeightLeft() - getHeightRight();
            if (bal>=2) {
                if (left.getHeightLeft()<left.getHeightRight())
                    left.rotateLeft(this);
                rotateRight(par);
            }
            else if (bal<=-2) {
                if (right.getHeightRight()<right.getHeightLeft())
                    right.rotateRight(this);
                rotateLeft(par);
            }
        }
    }

    static class AVLTree extends Node {
        public AVLTree(int sz) {
            size = 0;
            pool_max = sz;
            pool = new Node[sz];
            for (int i=0; i<sz; i++)
                pool[i] = new Node();
            pool_index=0;
        }

        public void clear() {
            left = null;
            size=0;
        }

        @Override
        public void insert(int d) {
            if (left==null)
                left = Node.createAndInsert(d);
            else {
                left.insert(d);
                left.rebalance(this);
            } 
        }

        @Override
        public void delete(int d) {
            left.delete(d);
        }

        @Override
        public int select(int k) {
            return left.select(k);
        }
    }

    public static void main(String args[]) throws IOException, NumberFormatException {
        //BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("ft.in")));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        String str[];
        AVLTree avltree = new AVLTree(10005);
        int te = Integer.parseInt(in.readLine());
        for (int as=0; as<te; as++) {
            str = in.readLine().split("\\s+");
            int n = Integer.parseInt(str[0]);
            final int sqrtn = (int)Math.sqrt(n)+1;
            str = in.readLine().split("\\s+");
            for (int i=0; i<n; i++) 
                people[i] = Integer.parseInt(str[i]);
            str = in.readLine().split("\\s+");
            int q = Integer.parseInt(str[0]);
            Q queries[] = new Q[q];
            for (int i=0; i<q; i++) {
                str = in.readLine().split("\\s+");
                int a = Integer.parseInt(str[0]);    
                int b = Integer.parseInt(str[1]);    
                int k = Integer.parseInt(str[2]);    
                queries[i] = new Q(a,b,k,i);
            }
            Arrays.sort(queries, new Comparator<Q>() {
                @Override
                public int compare(Q q1, Q q2) {
                    int x = q1.a/sqrtn;
                    int y = q2.a/sqrtn;
                    if (x==y) return q1.b-q2.b;
                    return x-y;
                }
            });
            int res[] = new int[q];
            boolean changeBlock = true;
            int a=0, b=0;
            for (int i=0; i<q; i++) {
                if (changeBlock) {
                    avltree.clear();
                    for (int j=queries[i].a; j<=queries[i].b; j++) {
                        avltree.insert(people[j]);
                    }
                    a = queries[i].a;
                    b = queries[i].b;
                    changeBlock = false;
                }
                else {
                    while (b<queries[i].b) {
                        b++;
                        avltree.insert(people[b]);
                    }
                    while (a>queries[i].a) {
                        a--;
                        avltree.insert(people[a]);
                    }
                    while (a<queries[i].a) {
                        avltree.delete(people[a]);
                        a++;
                    }
                }
                res[queries[i].i] = avltree.select(queries[i].k);
                if (i+1<q && queries[i].a/sqrtn < queries[i+1].a/sqrtn) changeBlock=true;
            } 
            for (int i=0; i<q; i++) {
                System.out.println(res[i]);
            }
        }
        //out.flush();
        in.close();
    }
}

