#ifndef TREE_HPP
#define TREE_HPP

#include "../utils/iterator_traits.hpp"
#include "../utils/iterator.hpp"
#include "../utils/utility.hpp"
#include "../utils/algorithm.hpp"
#include <stddef.h>
#include <iostream>

#ifndef nullptr
# define nullptr NULL
#endif

template<class T>
struct tree_node
{
	typedef T		value_type;
	value_type		value;
	tree_node		*parent;
	tree_node		*left;
	tree_node		*right;
};


template<typename T, typename container, typename value>
class	tree_iterator {
public:
	typedef	T		tree_node;

	typedef				value							value_type;
	typedef				value_type&						reference;
	typedef				value_type*						pointer;
	typedef				value_type						iterator_category;
	typedef				ptrdiff_t						difference_type;
	typedef	typename	ft::bidirectional_iterator_tag	iterator_catgeory;

private:
	tree_node	_current;

public:
	tree_iterator() : _current() {}
	tree_iterator(const tree_iterator<typename container::node *, container, typename container::value_type> & in) : _current(in.base()) { }
	tree_iterator(tree_node const &in) : _current(in) {}
	virtual ~tree_iterator() {}

	tree_node		&base() { return _current; }
	const tree_node	&base() const { return _current; }

	tree_iterator &operator++()
	{
		if (_current->right != nullptr){
			_current = _current->right;
			while (_current->left) {
				_current = _current->left;
			}
		}
		else {
			tree_node	c = _current;
			_current = _current->parent;
			while (_current->right == c)
			{
				c = _current;
				_current = _current->parent;
			}
		}
		return *this;
	}

	tree_iterator operator++(int)
	{
		tree_iterator tmp = *this;
		++(*this);
		return tmp;
	}

	tree_iterator &operator--()
	{
		if (_current->left != nullptr) {
			_current = _current->left;
			while (_current->right) {
				_current = _current->right;
			}
			
		}
		else {
			tree_node	c = _current;
			_current = _current->parent;
			while (_current->left == c) {
				c = _current;
				_current = _current->parent;
			}
		}
		return *this;
	}

	tree_iterator operator--(int)
	{
		tree_iterator tmp = *this;
		--(*this);
		return tmp;
	}

	tree_iterator	operator-(int const &i) const
	{
		tree_iterator ret = *this;
		for (int j = 0; j < i; j++) {
			ret--;
		}
		return ret;
	}

	tree_iterator	operator+(int const &i) const {
		tree_iterator ret = *this;
		for (int j = 0; j < i; j++) {
			ret++;
		}
		return ret;
	}

	pointer	operator->() { return &(this->operator*()); }
	pointer	operator->() const { return &(this->operator*()); }
	
	bool operator==(tree_iterator const &x) const
		{ return _current == x._current; }
	bool operator!=(tree_iterator const &x) const
		{ return !(*this == x); }

	value_type	&operator*()
		{ return _current->value; }
	value_type	&operator*() const
		{ return _current->value; }
};


template < class T, class Compare = std::less<T>,
		   class Allocator = std::allocator<T> >
class tree
{
public:
	typedef	T																	value_type;
	typedef	Compare																value_compare;
	typedef	Allocator															allocator_type;

	typedef typename Allocator::template rebind<tree_node<value_type> >::other	tree_node_allocator_type;
	typedef	tree_node<value_type>												node;
	typedef	tree_iterator<node *, tree, T>										iterator;
	typedef	tree_iterator<const node *, tree, const T>							const_iterator;
	typedef	ft::reverse_iterator<iterator>										reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>								const_reverse_iterator;
	typedef	size_t																size_type;

private:
	value_compare				_comp;
	allocator_type				_a;
	tree_node_allocator_type	_a_node;
	node						*_root;
	node						_dummy;
	size_type					_size;

// private:
public:

	node *create_node(const value_type& v)
	{
		node *new_node = _a_node.allocate(1);
		_a.construct(&new_node->value, v);
		new_node->parent = &_dummy;
		new_node->left = nullptr;
		new_node->right = nullptr;

		return new_node;
	}
	//v값을 가진 새 노드 깨끗깨끗

	node	*min(node *root) const
	{
		while (root && root->left && root != &_dummy) {
			root = root->left;
		}
		return root;
	}
	//왼쪽으로 내려가면서 가장 작은 녀석 리턴 근데 root != &_dummy 는 무엇?


	void	deleteTree(node *root)
	{
		if (root == nullptr) {
			return ;
		}

		deleteTree(root->left);
		deleteTree(root->right);

		_a.destroy(&root->value);
		_a_node.deallocate(root, 1);
	}

	//tree 전체삭제 왼쪽 오른쪽도 삭제요청시키고 본인도 삭제

	bool	equals(value_type const &first, value_type const &second) const
		{ return (!_comp(first, second) && !_comp(second, first)); }

	//같은값 _compare은 첫 번째 인수가 두 번째 인수 보다 작으면 true

	node	*search(node *root, const value_type &v) const
	{
		if (!root) {
			return nullptr;
		}
		if (equals(root->value, v)) {
			return root;
		}
		if (_comp(v, root->value) && root->left == nullptr) {
			return root;
		}
		if (!_comp(v, root->value) && root->right == nullptr) {
			return root;
		}
		if (!_comp(v, root->value)) {
			return search(root->right, v);
		}
		return search(root->left, v);
	}

	//v값을 root값이랑 비교하면서 search하기 작으면 왼쪽으로 아니면 오른쪽으로 이동


	void	node_insert(node *z){
		node *x = _root;
		node *y = nullptr;

		while (x != nullptr)
		{
			y = x;
			if (_comp(z->value, x->value)) {
				x = x->left;
			}
			else {
				x = x->right;
			}
		}
		z->parent = y;
		if (y == nullptr) {
			_root = z;
			_root->parent = &_dummy;
			_dummy.left = _root;
		}
		else if (_comp(z->value, y->value)) {
			y->left = z;
		}
		else {
			y->right = z;
		}

	}

	// find node that do not have a left child
	// in the subtree of the given node
	node	*successor(node *x)
	{
		node *tmp = x;

		while (tmp->left != nullptr) {
			tmp = tmp->left;
		}
		return tmp;
	}

	// find node that replaces a deleted node in the tree
	node	*replace(node *x)
	{
		// when leaf
		if (x->left == nullptr && x->right == nullptr)
			return nullptr;

		// when has a 1 child
		if (x->right == nullptr)
			return x->left;
		
		if (x->left == nullptr)
			return x->right;

		// when has 2 children
		return successor(x->right);
	}

	void	node_erase(node *v){
		node *u  = replace(v);

		if (u == nullptr) // leaf
		{
			if (v == _root)
			{
				_root = nullptr;
				_dummy.left = &_dummy;
			}
			else
			{
				if (v == v->parent->left) {
					v->parent->left = nullptr;
				}
				else {
					v->parent->right = nullptr;
				}
			}
			_a.destroy(&v->value);
			_a_node.deallocate(v, 1);
			return ;
		}

		if (v->left == nullptr || v->right == nullptr) // only one child
		{
			if (v == _root)
			{
				_root = u;
				_root->parent = &_dummy;
				_a.destroy(&v->value);
				_a_node.deallocate(v, 1);
			}
			else
			{
				if (v == v->parent->left) {
					v->parent->left = u;
				}
				else {
					v->parent->right = u;
				}
				u->parent = v->parent;
				_a.destroy(&v->value);
				_a_node.deallocate(v, 1);
			}
			return ;
		}
		else {	// two children
			if (v == _root) {
				_root = u;
			}
			if (v->parent && v->parent->left == v) {
				v->parent->left = u;
			} 
			else if (v->parent && v->parent->right == v) {
				v->parent->right = u;
			}
			if (u->right) {
				v->right->parent = u;
			}
			if (u->left) {
				v->left->parent = u;
			}
			if (u->parent && u == u->parent->left) {
				u->parent->left = v;
			}
			if (u->parent && u == u->parent->right) {
				u->parent->right = v;
			}
			_a.destroy(&v->value);
			_a_node.deallocate(v, 1);
			return ;	
		}
	}


public:
	tree(const value_compare& comp, const allocator_type& a)
		: _comp(comp),
		  _a(a),
		  _a_node(a),
		  _root(nullptr),
		  _dummy(),
		  _size(0)
	{
		_dummy.left = &_dummy;
		_dummy.right = nullptr;
	}

	tree(const tree &x)
		: _comp(x._comp),
		  _a(x._a),
		  _a_node(x._a_node),
		  _root(),
		  _dummy(),
		  _size(0)
	{
		const_iterator it = x.begin();
		while (it != x.end())
		{
			insert(*it);
			++it;
		}
	}

	tree	&operator=(const tree & x) {
		if (this != &x) {
			this->clear();
			_size = 0;
			_comp = x._comp;
			_a = x._a;
			_a_node = x._a_node;
			_root = nullptr;
			const_iterator it = x.begin();
			while (it != x.end())
			{
				insert(*it);
				++it;
			}
		}
		return *this;
	}

	~tree()
	{
		clear();
	}

	iterator begin()
		{return iterator(min(_dummy.left));}
	const_iterator begin() const
		{return const_iterator(min(_dummy.left));}
	iterator end()
		{return iterator(&_dummy);}
	const_iterator end() const
		{return const_iterator(&_dummy);}

	size_type size() const {return _size;}
	size_type max_size() const {return _a_node.max_size();}

	ft::pair<iterator, bool> insert(const value_type& v)
	{
		node	*z;

		z = search(_root, v);
		if (z && equals(v, z->value))
			return ft::make_pair(iterator(z), false);
		z = create_node(v);
		_dummy.left = _root;
		node_insert(z);
		_size++;

		return ft::make_pair(iterator(z), true);
	}

	size_type 	erase (const value_type& v)
	{
		node	*z = search(_root, v);
		if (!z || !equals(v, z->value))
			return 0;
		node_erase(z);

		_size--;
		return 1;
	}

	void 		swap (tree& x)
	{
		if (this != &x)
		{
			ft::swap(_dummy.left, x._dummy.left);
			ft::swap(_root, x._root);
			ft::swap(_a, x._a);
			ft::swap(_a_node, x._a_node);
			ft::swap(_comp, x._comp);
			ft::swap(_size, x._size);
			_root->parent = &_dummy;
			x._root->parent = &x._dummy;
		}
	}

	void	clear()
	{
		deleteTree(_root);
		_dummy.left = &_dummy;
		_root = nullptr;
		_size = 0;
	}

	iterator find(const value_type& v)
	{
		node *res = search(_root, v);
		if (!res || !equals(res->value, v))
			return end();
		return iterator(res);
	}

	const_iterator find(const value_type& v) const
	{
		node *res = search(_root, v);
		if (!res || !equals(res->value, v))
			return end();
		return const_iterator(res);
	}
};


#endif