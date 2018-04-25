#ifndef SETLIST_H
#define SETLIST_H

#include<algorithm>
#include<vector>
#include<iterator>
#include<iostream>

using namespace std;

template
<typename T>
class SetList
{
	private:
		struct ListNode
		{
			public:
				T info;
				ListNode* next;
				ListNode(T i,ListNode* n):info(i),next(n){}
		};
		ListNode* head;
	public:
		struct iterator
		{
			typedef std::forward_iterator_tag iterator_category;
			typedef iterator self_type;
			typedef T valuetype;
			typedef T& reference;
			typedef T* pointer;
			typedef ptrdiff_t difference_type;
			private:
				ListNode* buf;
			public:
				iterator(ListNode* ptr):buf(ptr){}
				self_type operator++(){buf = buf->next; return *this;}
				self_type operator++(int postfix){self_type cpy = *this;buf = buf= buf->next;return cpy;}
				reference operator*(){return buf->info;}
				self_type operator->(){return buf;}
				bool operator==(const self_type& rhs){return buf == rhs.buf;}
				bool operator!=(const self_type& rhs){return buf != rhs.buf;} 
		};
		SetList(){head = nullptr;}
		iterator insert(const T& ins)
		{	
			if(find(ins) == nullptr)
			{
				head = new ListNode(ins,head);
			}
		}	
		iterator find(const T& item)
		{
			for(ListNode* p = head;p != nullptr;p = p->next)
			{
				if(p->info == item)
				{
					return iterator(p);
				}
			}
			return iterator(nullptr);
		}
		iterator begin(){return iterator(head);}
		iterator end(){return iterator(nullptr);}
		~SetList()
		{
			ListNode* del;
			for(ListNode* p = head;p != nullptr;)
			{
				del = p;
				p = p-> next;
				delete del;
			}
		}
};
#endif
