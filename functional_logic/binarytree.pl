% CA341 Assignment 2
% binary tree in prolog

% Ailbhe Byrne
% 19424402

% binary tree: binTree(Root, Left, Right), (reference: David Sinclairs notes for CA208)

binTree(_, _, _).


% insert value into a binary tree: insert(X, T, R), add X to tree T to get tree R, (reference: David Sinclairs notes for CA208)

% if adding to empty tree, root becomes X (base case)
% if X is less than root node, add to left side of tree
% if X is greater than root node, add to right side of tree

insert(X, nil, binTree(X, nil, nil)) :- !.

insert(X, binTree(A, Left, Right), binTree(A, NewLeft, Right)) :- X < A, insert(X, Left, NewLeft), !.

insert(X, binTree(A, Left, Right), binTree(A, Left, NewRight)) :- X > A, insert(X, Right, NewRight), !.


% search a binary tree: search(X, T), return true if X is in tree T

% if searching empty tree, return false (base case)
% if X is root node, node found, return true (base case)
% if X is less than root node, search left side
% if X is greater than root node, search right side

search(_, nil) :- !, false.

search(X, binTree(X, _, _)) :- true, !.

search(X, binTree(A, Left, _)) :- X < A, search(X, Left), !.

search(X, binTree(A, _, Right)) :- X > A, search(X, Right), !.


% list nodes of tree using preorder traversal, preorder(T, L), where L is a list of the nodes of tree T in preorder

% if traversing an empty tree, L is [] (base case)
% if root X does not have children, L is [X] (base case)
% if root X has left and right children, traverse left child, traverse right child, L is [X, left nodes, right nodes]

preorder(nil, []) :- !.

preorder(binTree(X, nil, nil), [X]).

preorder(binTree(X, Left, Right), L) :- preorder(Left, LeftLst), preorder(Right, RightLst), append([[X], LeftLst, RightLst], L), !.


% list nodes of tree using inorder traversal, inorder(T, L), where L is a list of the nodes of tree T in order

% if traversing an empty tree, L is [] (base case)
% if root X does not have children, L is [X] (base case)
% if root X has left and right children, traverse left child, traverse right child, L is [left nodes, X, right nodes]

inorder(nil, []) :- !.

inorder(binTree(X, nil, nil), [X]).

inorder(binTree(X, Left, Right), L) :- inorder(Left, LeftLst), inorder(Right, RightLst), append([LeftLst, [X], RightLst], L), !.


% list nodes of tree using postorder traversal, postorder(T, L), where L is a list of the nodes of tree T in postorder

% if traversing an empty tree, L is [] (base case)
% if root X does not have children, L is [X] (base case)
% if root X has left and right children, traverse left child, traverse right child, L is [left nodes, right nodes, X]

postorder(nil, []) :- !.

postorder(binTree(X, nil, nil), [X]).

postorder(binTree(X, Left, Right), L) :- postorder(Left, LeftLst), postorder(Right, RightLst), append([LeftLst, RightLst, [X]], L), !.
