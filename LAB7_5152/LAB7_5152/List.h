#pragma once

template <class T>
class List
{
public:
	List(T* item);
	List();
	~List();
	void Add(T* item);
	T* Find(int index);
	int IndexOf(T* item);
	void Remove(T* item);
	void RemoveAt(int index);
	int GetCount();
	void Clear();
private:
	struct ListItem
	{
		T* Item;
		ListItem* NextItem;
		ListItem* PrevItem;
	};
	ListItem* _head;
	int _count;
};


template<class T>
List<T>::List(T * item)
{
	_head = new ListItem();
	_head->Item = item;
	_head->NextItem = nullptr;
	_head->PrevItem = nullptr;
	_count = 1;
}

template<class T>
List<T>::List()
{
	_head = nullptr;
	_count = 0;
}

template<class T>
List<T>::~List()
{

}

template<class T>
void List<T>::Add(T * item)
{
	if (_count > 0)
	{
		ListItem* listItem = new ListItem;
		listItem->Item = item;
		listItem->NextItem = nullptr;
		ListItem* currentItem = _head;
		for (int i = 1; i < _count; i++)
		{

			currentItem = currentItem->NextItem;
		}
		currentItem->NextItem = listItem;
		listItem->PrevItem = currentItem;
		_count++;
	}
	else
		if (_count == 0)
		{
			ListItem* listItem = new ListItem;
			listItem->Item = item;
			listItem->NextItem = nullptr;
			listItem->PrevItem = nullptr;
			_head = listItem;
			_count = 1;
		}
}

template<class T>
T * List<T>::Find(int index)
{
	if (index > _count || index < 0)
	{
		return nullptr;
	}
	else
	{
		if (index > _count || index < 1)
		{

			return _head->Item;
		}
		else
		{
			ListItem* currentItem;
			currentItem = _head;
			for (int i = 1; i <= index; i++)
			{

				currentItem = currentItem->NextItem;
			}
			return currentItem->Item;
		}
	}
}

template<class T>
int List<T>::IndexOf(T * item)
{
	int i = 0;
	int result = -1;
	for (i = 0; (i < _count); i++)
	{
		if ((*Find(i) == *item))
		{
			result = i;
		}
	}

	return result;
}

template<class T>
void List<T>::Remove(T * item)
{
	int index = IndexOf(item);
	if (index == 0)
	{
		if (_head != nullptr)
		{
			delete _head;
			_count = 0;
		}
	}
	else
		if (index == _count - 1)
		{
			ListItem* currentItem = _head;
			for (int i = 1; i <= _count - 1; i++)
			{
				currentItem = currentItem->NextItem;
			}
			ListItem* currentTmpItem = currentItem;
			currentItem = currentItem->PrevItem;
			currentItem->NextItem = nullptr;
			delete currentTmpItem;
			_count--;
		}
		else
			if (index >0)
			{
				ListItem* currentItem = _head;
				for (int i = 1; i <= index; i++)
				{
					currentItem = currentItem->NextItem;
				}
				ListItem* currentTmpItem = currentItem;
				currentItem->NextItem->PrevItem = currentItem->PrevItem;
				currentItem->PrevItem->NextItem = currentItem->NextItem;
				delete currentTmpItem;
				_count--;
			}
}

template<class T>
void List<T>::RemoveAt(int index)
{
	Remove(Find(index));
}

template<class T>
int List<T>::GetCount()
{
	return _count;
}

template<class T>
void List<T>::Clear()
{
	for (int i = _count - 1; i > 0; i--)
		RemoveAt(i);
	_head->NextItem = nullptr;
	delete _head;
	_head = nullptr;
	_count = 0;
}


