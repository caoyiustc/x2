/*
 * List_macros.h
 *
 *  Created on: 2017年3月24日
 *      Author: 13774
 */

#ifndef INCLUDE_MACROS_LIST_MACROS_H_
#define INCLUDE_MACROS_LIST_MACROS_H_

#include <List.h>

//============函数宏区
//=========class : ListNode
template<class T>
ListNode<T>* ListNode<T>::getNext()const
{
    return next;
}

template<class T>
ListNode<T>* ListNode<T>::getPrevious()const
{
    return previous;
}
template<class T>
void ListNode<T>::setNext(ListNode<T>* next)
{
    this->next = next;
}

template<class T>
void  ListNode<T>::setPrevious(ListNode<T>* previous)
{
    this->previous = previous;
}
template<class T>
int  ListNode<T>::hasPrevious()const
{
    return (this->previous!=NULL);
}
//template<class T>
//void ListNode<T>::adjustOffset(char **p,ptrdiff_t diff)
//{
//	if(p!=NULL && *p!=NULL)*p+=diff;
//}
template<class T>
int  ListNode<T>::hasNext()const
{
    return (this->next!=NULL);
}

template<class T>
const T& ListNode<T>::getData()const
{
    return data;
}
template<class T>
T& ListNode<T>::getData()
{
    return data;
}
template<class T>
void ListNode<T>::setData(const T& data)
{
    this->data=data;
}
//=============class:LinkedList
template <class T,template <class> class _Allocator>
ListNode<T>* LinkedList<T,_Allocator >::getHead()const
{
    return root->getNext();
}
template<class T,template <class> class _Allocator>
ListNode<T>*  LinkedList<T,_Allocator>::getLast()const
{
    return last->getNext();
}
template <class T,template <class> class _Allocator>
bool			LinkedList<T,_Allocator>::isEmpty()const
{
	return this->getHead()==NULL;
}
template <class T,template <class> class _Allocator>
_Allocator<ListNode<T> > *LinkedList<T,_Allocator>::getMemoryManager()const
{
    return smm;
}

//=====class: SimpleMemoryNode
SimpleMemoryNode::SimpleMemoryNode(bool NO):
NO(NO)
{

}
bool SimpleMemoryNode::getNO()
{
    return this->NO;
}
bool SimpleMemoryNode::isFree()
{
    return this->NO==false;
}
void SimpleMemoryNode::free()
{
    this->NO=false;
}
void SimpleMemoryNode::unfree()
{
    this->NO=true;
}
void SimpleMemoryNode::setNO(bool NO)
{
    this->NO = NO;
}

//=====class:SimpleMemoryManager
template<class T>
bool SimpleMemoryManager<T>::isFull()const
{
    return this->curSize==this->len;
}
template<class T>
size_t SimpleMemoryManager<T>::getLen()const
{
    return this->len;
}
template<class T>
size_t SimpleMemoryManager<T>::getCurSize()const
{
    return this->curSize;
}
template<class T>
size_t SimpleMemoryManager<T>::getStart()const
{
    return this->start;
}
template<class T>
size_t SimpleMemoryManager<T>::getLimit()const
{
    return this->limit;
}    ///////////

template<class T>
size_t  SimpleMemoryManager<T>::getNodeSize()
{
	return sizeof(Node);
}

template<class T>
typename SimpleMemoryManager<T>::ERROR_HANDLER SimpleMemoryManager<T>::getErrHandler()
{
	return this->errhandle;
}
template<class T>
void			SimpleMemoryManager<T>::setErrHandler(SimpleMemoryManager<T>::ERROR_HANDLER errhandle)
{
	this->errhandle= errhandle;
}
template<class T>
bool			SimpleMemoryManager<T>::checkIsInternal(Node *t)
{
	return this->start <= (size_t)t && (size_t)t - (size_t)this->start <= this->limit ;
}
//===========class TreeNode

template<class T>
  TreeNode<T>* TreeNode<T>::setSon(TreeNode<T>* son)
  {
#if defined(CODE64)
	//printf("setSon is : %x \n",son);
#endif
  	this->son=son;
  }
template<class T>
TreeNode<T>* TreeNode<T>::setFather(TreeNode<T>* father) {
    this->father=father;
}

template<class T>
TreeNode<T>* TreeNode<T>::getSon() const{
#if defined(CODE64)
//	printf("gettSon \n");
#endif
	return son;
}

template<class T>
TreeNode<T>* TreeNode<T>::getDirectFather()const {//direct father
#if defined(CODE64)
//	printf("call direct,this is %x,father is %x\n",this,this->father);
#endif
    return father;
}

template<class T>
bool		 TreeNode<T>::hasSon()const
{
	return this->son!=NULL;
}
template<class T>
bool 		 TreeNode<T>::hasFather()const
{
	return this->father!=NULL;
}

//======class Tree
template<class T,template <class> class _Allocator>
TreeNode<T>* Tree<T,_Allocator>::getHead()const {
	return root->getSon();
}

template<class T,template <class> class _Allocator>
void  Tree<T,_Allocator>::setHead(TreeNode<T> *head)
 {
#if defined(CODE64)
	//printf("root : %x  , head : %x\n",root,head);
	//head->setFather(root);
	//head->setSon(root);
	//printf("head data : %x \n",head->getDirectFather());
#endif
 	root->setSon(head);
#if defined(CODE64)
 	//printf("root->setSon : %x\n",root->getSon());
#endif
 }

template<class T,template <class> class _Allocator>
void		Tree<T,_Allocator>::addRoot(TreeNode<T>* node)
{
	this->root->addSon(node);
}
template<class T,template <class> class _Allocator>
bool		Tree<T,_Allocator>::isEmpty()const
{
	return !(this->root->hasSon());
}
template<class T,template <class> class _Allocator>
_Allocator<TreeNode<T> >*	Tree<T,_Allocator>::getSmm()const
{
	return this->smm;
}



#endif /* INCLUDE_MACROS_LIST_MACROS_H_ */
