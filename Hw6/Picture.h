#include "Shape.h"
#include<iostream>
using namespace std;

class Picture
{
	public:
		Picture()
		{
			 head = nullptr;
		}
		void add(Shape* sp)
		{
			head = new shapeListNode(sp,head);
		}
		double totalArea()
		{
			double ret = 0.0;
			for(shapeListNode* P = head;P;P=P->next)
			{
				ret += P->shape->area();
			}
			return ret;
		}
		void drawAll()
		{
			for(shapeListNode* p = head;p;p=p->next)
			{
				p->shape->draw();
			}
		}
		~Picture()
		{
			head->deleteLinkedList(head);
		}

	private:
		struct shapeListNode
		{
			Shape* shape;
			shapeListNode* next;
			shapeListNode(Shape* s,shapeListNode* newNext):shape(s),next(newNext)
			{
			}
			void deleteLinkedList(shapeListNode* L)
			{
				while(L)
				{
					shapeListNode* p = L;
					L = L->next;
					delete p->shape;
					delete p;
				}
			}
		};
		shapeListNode* head;
};
