-- CA341 Assignment 2
-- binary tree in haskell

-- Ailbhe Byrne
-- 19424402

-- binary tree (reference: David Sinclair's notes for CA320)

-- pattern can match an empty tree or a tree with a root value and a left and right child

data BinTree t = Empty | Root t (BinTree t) (BinTree t)
                 deriving (Eq, Ord, Show)


-- insert a value into a binary tree

-- if tree is empty, x becomes root (base case)
-- if x is less than root node, add to left side, otherwise add to right side

insert :: Ord a => a -> BinTree a -> BinTree a

insert x Empty = Root x Empty Empty
insert x (Root a left right) = if x < a
                               then Root a (insert x left) right
                               else Root a left (insert x right)


-- search a binary tree, returns true if x is in binary tree

-- if searching an empty tree, return false (base case)
-- if x == a, node found, return true
-- if x is less than root node, search left side, otherwise search right side

search :: Ord a => a -> BinTree a -> Bool

search x Empty = False
search x (Root a left right)
   | x == a = True
   | x < a = search x left
   | x > a = search x right


-- list nodes of tree using preorder traversal

-- if traversing an empty tree, return [] (base case)
-- otherwise add root node to list, then traverse left side, then traverse right side

preorder :: BinTree a -> [a]

preorder Empty = []
preorder (Root x left right) = [x] ++ preorder left ++ preorder right


-- list nodes of tree using inorder traversal

-- if traversing an empty tree, return [] (base case)
-- otherwise traverse left side, then add root node to list, then traverse right side

inorder :: BinTree a -> [a]

inorder Empty = []
inorder (Root x left right) = inorder left ++ [x] ++ inorder right


-- list nodes of tree using postorder traversal

-- if traversing an empty tree, return [] (base case)
-- otherwise traverse left side, then traverse right side, then add root node to list

postorder :: BinTree a -> [a]

postorder Empty = []
postorder (Root x left right) = postorder left ++ postorder right ++ [x]
