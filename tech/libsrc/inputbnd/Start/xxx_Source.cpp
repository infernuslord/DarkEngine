
//----- (008D39A5) --------------------------------------------------------
char *__cdecl SkipWhiteSpace(char **str)
{
	char v2; // [sp+0h] [bp-4h]@1

	while (1)
	{
		v2 = **str;
		if (v2 != 32)
			break;
		if (!v2 || v2 == 13 || v2 == 10)
			break;
		++*str;
	}
	return *str;
}

//----- (008D39EE) --------------------------------------------------------
void __cdecl GetChunk(char *dest, char **src, char ch1, char ch2)
{
	char v4; // [sp+0h] [bp-4h]@1

	while (1)
	{
		v4 = **src;
		if (v4 == ch1)
			break;
		if (v4 == ch2 || v4 == 61 || !v4 || v4 == 13 || v4 == 10)
			break;
		*dest++ = *(*src)++;
	}
	*dest = 0;
	if (v4 != 61 && v4 && v4 != 13)
	{
		if (v4 != 10)
			++*src;
	}
}

//----- (008D3A95) --------------------------------------------------------
void __thiscall cIBVariableManager::GlueTokens(cIBVariableManager *this, char *dest, char **tokens, int num_tokens)
{
	int i; // [sp+4h] [bp-4h]@1

	*dest = 0;
	for (i = 0; i < num_tokens; ++i)
	{
		if (i)
			strcat(dest, " ");
		strcat(dest, tokens[i]);
	}
}

//----- (008D3AF3) --------------------------------------------------------
void __thiscall cIBVariableManager::FreeTokens(cIBVariableManager *this, char **tokens, int num_tokens)
{
	int i; // [sp+Ch] [bp-4h]@1

	for (i = 0; i < num_tokens; ++i)
		operator delete(tokens[i]);
	operator delete(tokens);
}

//----- (008D3B48) --------------------------------------------------------
void __thiscall cIBVariableManager::TokensToStr(cIBVariableManager *this, char *str, int str_len, char **tokens, int num_tokens)
{
	size_t v5; // esi@3
	int i; // [sp+8h] [bp-4h]@1

	this->m_misc_str[0] = 0;
	for (i = 0; i < num_tokens; ++i)
	{
		v5 = strlen(str);
		if (strlen(tokens[i]) + v5 >= str_len)
			break;
		strcat(str, tokens[i]);
		if (i < num_tokens - 1)
			strcat(str, " ");
	}
}

//----- (008D3BE0) --------------------------------------------------------
void __thiscall intrnl_var::intrnl_var(intrnl_var *this)
{
	aatree<_intrnl_var_channel>::aatree<_intrnl_var_channel>(&this->channels);
}

//----- (008D3C00) --------------------------------------------------------
void __thiscall aatree<_intrnl_var_channel>::aatree<_intrnl_var_channel>(aatree<_intrnl_var_channel> *this)
{
	aatree<_intrnl_var_channel> *v1; // ST0C_4@1
	void *v2; // eax@1

	v1 = this;
	v2 = j__new(0x1Eu, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 70);
	v1->null_node = (aatree<_intrnl_var_channel>::aa_node *)v2;
	v1->root = (aatree<_intrnl_var_channel>::aa_node *)v2;
	v1->num_nodes = 0;
	v1->null_node->level = 0;
	v1->null_node->name = 0;
	v1->null_node->info = 0;
	v1->root = v1->null_node;
	v1->null_node->right = v1->root;
	v1->null_node->left = v1->null_node->right;
}

//----- (008D3CA0) --------------------------------------------------------
void __thiscall aatree<_intrnl_var_channel>::Add(aatree<_intrnl_var_channel> *this, char *name, _intrnl_var_channel *info, int info_array_size)
{
	aatree<_intrnl_var_channel>::Insert(this, name, info, &this->root, this->null_node, info_array_size);
}

//----- (008D3CD0) --------------------------------------------------------
int __thiscall aatree<_intrnl_var_channel>::Delete(aatree<_intrnl_var_channel> *this, char *name, int delete_info, _intrnl_var_channel *info)
{
	aatree<_intrnl_var_channel> *v4; // ST10_4@1
	int v5; // ST14_4@1

	v4 = this;
	v5 = aatree<_intrnl_var_channel>::Remove(this, name, &this->root, delete_info, info);
	aatree<_intrnl_var_channel>::ResetParents(v4, v4->root, 0);
	return v5;
}

//----- (008D3D20) --------------------------------------------------------
void __thiscall aatree<_intrnl_var_channel>::DeleteAll(aatree<_intrnl_var_channel> *this, int delete_info)
{
	aatree<_intrnl_var_channel> *v2; // ST08_4@1

	v2 = this;
	aatree<_intrnl_var_channel>::FreeTree(this, &this->root, delete_info);
	v2->root = v2->null_node;
}

//----- (008D3D50) --------------------------------------------------------
_intrnl_var_channel *__thiscall aatree<_intrnl_var_channel>::Find(aatree<_intrnl_var_channel> *this, char *name)
{
	return aatree<_intrnl_var_channel>::Search(this, name, this->root);
}

//----- (008D3D70) --------------------------------------------------------
int __thiscall aatree<_intrnl_var_channel>::GetNumNodes(aatree<_intrnl_var_channel> *this)
{
	return this->num_nodes;
}

//----- (008D3D80) --------------------------------------------------------
void __thiscall aatree<_intrnl_var_channel>::ResetVisited(aatree<_intrnl_var_channel> *this, aatree<_intrnl_var_channel>::aa_node *cur)
{
	aatree<_intrnl_var_channel> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!cur)
	{
		cur = this->root;
		this->cur_visited = this->root;
	}
	if (cur != this->null_node)
	{
		aatree<_intrnl_var_channel>::ResetVisited(this, cur->left);
		aatree<_intrnl_var_channel>::ResetVisited(thisa, cur->right);
		cur->visited = 0;
	}
}

//----- (008D3DE0) --------------------------------------------------------
void __thiscall aatree<_intrnl_var_channel>::VisitBefore(aatree<_intrnl_var_channel> *this, _intrnl_var_channel *info, aatree<_intrnl_var_channel>::aa_node *cur)
{
	aatree<_intrnl_var_channel> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!cur)
	{
		cur = this->root;
		this->cur_visited = this->root;
	}
	if (cur != this->null_node)
	{
		aatree<_intrnl_var_channel>::VisitBefore(this, info, cur->left);
		if (cur->info != info)
		{
			aatree<_intrnl_var_channel>::VisitBefore(thisa, info, cur->right);
			cur->visited = 1;
		}
	}
}

//----- (008D3E50) --------------------------------------------------------
_intrnl_var_channel *__thiscall aatree<_intrnl_var_channel>::GetNextInOrder(aatree<_intrnl_var_channel> *this, char *str)
{
	_intrnl_var_channel *result; // eax@2
	aatree<_intrnl_var_channel> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->cur_visited == this->null_node)
	{
		result = 0;
	}
	else
	{
		if (this->cur_visited->left == this->null_node || this->cur_visited->left->visited)
		{
			if (this->cur_visited->visited)
			{
				if (this->cur_visited->right == this->null_node || this->cur_visited->right->visited)
				{
					this->cur_visited = this->cur_visited->parent;
					result = aatree<_intrnl_var_channel>::GetNextInOrder(this, str);
				}
				else
				{
					this->cur_visited = this->cur_visited->right;
					result = aatree<_intrnl_var_channel>::GetNextInOrder(this, str);
				}
			}
			else
			{
				this->cur_visited->visited = 1;
				if (str)
					strcpy(str, this->cur_visited->name);
				result = thisa->cur_visited->info;
			}
		}
		else
		{
			this->cur_visited = this->cur_visited->left;
			result = aatree<_intrnl_var_channel>::GetNextInOrder(this, str);
		}
	}
	return result;
}

//----- (008D3F50) --------------------------------------------------------
void __thiscall aatree<intrnl_var>::aatree<intrnl_var>(aatree<intrnl_var> *this)
{
	aatree<intrnl_var> *v1; // ST0C_4@1
	void *v2; // eax@1

	v1 = this;
	v2 = j__new(0x1Eu, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 70);
	v1->null_node = (aatree<intrnl_var>::aa_node *)v2;
	v1->root = (aatree<intrnl_var>::aa_node *)v2;
	v1->num_nodes = 0;
	v1->null_node->level = 0;
	v1->null_node->name = 0;
	v1->null_node->info = 0;
	v1->root = v1->null_node;
	v1->null_node->right = v1->root;
	v1->null_node->left = v1->null_node->right;
}

//----- (008D3FF0) --------------------------------------------------------
void __thiscall aatree<intrnl_var>::_aatree<intrnl_var>(aatree<intrnl_var> *this)
{
	aatree<intrnl_var>::DeleteAll(this, 1);
}

//----- (008D4010) --------------------------------------------------------
void __thiscall aatree<intrnl_var>::Add(aatree<intrnl_var> *this, char *name, intrnl_var *info, int info_array_size)
{
	aatree<intrnl_var>::Insert(this, name, info, &this->root, this->null_node, info_array_size);
}

//----- (008D4040) --------------------------------------------------------
int __thiscall aatree<intrnl_var>::Delete(aatree<intrnl_var> *this, char *name, int delete_info, intrnl_var *info)
{
	aatree<intrnl_var> *v4; // ST10_4@1
	int v5; // ST14_4@1

	v4 = this;
	v5 = aatree<intrnl_var>::Remove(this, name, &this->root, delete_info, info);
	aatree<intrnl_var>::ResetParents(v4, v4->root, 0);
	return v5;
}

//----- (008D4090) --------------------------------------------------------
intrnl_var *__thiscall aatree<intrnl_var>::Find(aatree<intrnl_var> *this, char *name)
{
	return aatree<intrnl_var>::Search(this, name, this->root);
}

//----- (008D40B0) --------------------------------------------------------
void __thiscall aatree<intrnl_var>::ResetVisited(aatree<intrnl_var> *this, aatree<intrnl_var>::aa_node *cur)
{
	aatree<intrnl_var> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!cur)
	{
		cur = this->root;
		this->cur_visited = this->root;
	}
	if (cur != this->null_node)
	{
		aatree<intrnl_var>::ResetVisited(this, cur->left);
		aatree<intrnl_var>::ResetVisited(thisa, cur->right);
		cur->visited = 0;
	}
}

//----- (008D4110) --------------------------------------------------------
intrnl_var *__thiscall aatree<intrnl_var>::GetNextInOrder(aatree<intrnl_var> *this, char *str)
{
	intrnl_var *result; // eax@2
	aatree<intrnl_var> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->cur_visited == this->null_node)
	{
		result = 0;
	}
	else
	{
		if (this->cur_visited->left == this->null_node || this->cur_visited->left->visited)
		{
			if (this->cur_visited->visited)
			{
				if (this->cur_visited->right == this->null_node || this->cur_visited->right->visited)
				{
					this->cur_visited = this->cur_visited->parent;
					result = aatree<intrnl_var>::GetNextInOrder(this, str);
				}
				else
				{
					this->cur_visited = this->cur_visited->right;
					result = aatree<intrnl_var>::GetNextInOrder(this, str);
				}
			}
			else
			{
				this->cur_visited->visited = 1;
				if (str)
					strcpy(str, this->cur_visited->name);
				result = thisa->cur_visited->info;
			}
		}
		else
		{
			this->cur_visited = this->cur_visited->left;
			result = aatree<intrnl_var>::GetNextInOrder(this, str);
		}
	}
	return result;
}

//----- (008D4210) --------------------------------------------------------
void __thiscall aatree<_intrnl_var_channel>::Insert(aatree<_intrnl_var_channel> *this, char *name, _intrnl_var_channel *info, aatree<_intrnl_var_channel>::aa_node **T, aatree<_intrnl_var_channel>::aa_node *parent, int info_array_size)
{
	size_t v6; // eax@2
	aatree<_intrnl_var_channel> *thisa; // [sp+0h] [bp-Ch]@1

	thisa = this;
	if (*T == this->null_node)
	{
		++this->num_nodes;
		*T = (aatree<_intrnl_var_channel>::aa_node *)j__new(0x1Eu, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 189);
		v6 = strlen(name);
		(*T)->name = (char *)j__new(v6 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 190);
		strcpy((*T)->name, name);
		(*T)->info = info;
		(*T)->info_array_size = info_array_size;
		(*T)->right = thisa->null_node;
		(*T)->left = (*T)->right;
		(*T)->parent = parent;
		(*T)->level = 1;
		(*T)->visited = 0;
		return;
	}
	if (strcmp(name, (*T)->name) <= 0)
	{
		aatree<_intrnl_var_channel>::Insert(thisa, name, info, &(*T)->left, *T, info_array_size);
	LABEL_8:
		aatree<_intrnl_var_channel>::Skew(thisa, T);
		aatree<_intrnl_var_channel>::Split(thisa, T);
		return;
	}
	if (strcmp(name, (*T)->name) > 0)
	{
		aatree<_intrnl_var_channel>::Insert(thisa, name, info, &(*T)->right, *T, info_array_size);
		goto LABEL_8;
	}
}

//----- (008D4390) --------------------------------------------------------
void __thiscall aatree<_intrnl_var_channel>::ResetParents(aatree<_intrnl_var_channel> *this, aatree<_intrnl_var_channel>::aa_node *cur, aatree<_intrnl_var_channel>::aa_node *parent)
{
	aatree<_intrnl_var_channel> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!parent)
		parent = this->null_node;
	if (cur != this->null_node)
	{
		cur->parent = parent;
		aatree<_intrnl_var_channel>::ResetParents(this, cur->left, cur);
		aatree<_intrnl_var_channel>::ResetParents(thisa, cur->right, cur);
	}
}

//----- (008D43F0) --------------------------------------------------------
int __thiscall aatree<_intrnl_var_channel>::Remove(aatree<_intrnl_var_channel> *this, char *name, aatree<_intrnl_var_channel>::aa_node **T, int delete_info, _intrnl_var_channel *info)
{
	size_t v5; // eax@11
	signed int v6; // edx@19
	aatree<_intrnl_var_channel> *thisa; // [sp+0h] [bp-14h]@1

	thisa = this;
	if (*T != this->null_node)
	{
		last_ptr = *T;
		if (strcmp(name, (*T)->name) >= 0)
		{
			del_ptr = *T;
			aatree<_intrnl_var_channel>::Remove(thisa, name, &(*T)->right, delete_info, info);
		}
		else
		{
			aatree<_intrnl_var_channel>::Remove(thisa, name, &(*T)->left, delete_info, info);
		}
		if (*T == last_ptr)
		{
			if (del_ptr == thisa->null_node || strcmp(name, del_ptr->name) || info && del_ptr->info != info)
			{
				item_found = 0;
			}
			else
			{
				operator delete(del_ptr->name);
				if (del_ptr != *T)
				{
					v5 = strlen((*T)->name);
					del_ptr->name = (char *)j__new(v5 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 431);
					strcpy(del_ptr->name, (*T)->name);
					if (delete_info)
						operator delete(del_ptr->info);
					del_ptr->info_array_size = (*T)->info_array_size;
					del_ptr->info = (*T)->info;
				}
				*T = (*T)->right;
				del_ptr = thisa->null_node;
				operator delete(last_ptr);
				--thisa->num_nodes;
				item_found = 1;
			}
		}
		else
		{
			if ((*T)->left->level < (*T)->level - 1 || (*T)->right->level < (*T)->level - 1)
			{
				v6 = (*T)->right->level;
				--(*T)->level;
				if (v6 > (*T)->level)
					(*T)->right->level = (*T)->level;
				aatree<_intrnl_var_channel>::Skew(thisa, T);
				aatree<_intrnl_var_channel>::Skew(thisa, &(*T)->right);
				aatree<_intrnl_var_channel>::Skew(thisa, &(*T)->right->right);
				aatree<_intrnl_var_channel>::Split(thisa, T);
				aatree<_intrnl_var_channel>::Split(thisa, &(*T)->right);
			}
		}
	}
	return 1;
}

//----- (008D46B0) --------------------------------------------------------
void __thiscall aatree<_intrnl_var_channel>::FreeTree(aatree<_intrnl_var_channel> *this, aatree<_intrnl_var_channel>::aa_node **T, int delete_info)
{
	aatree<_intrnl_var_channel> *thisa; // [sp+0h] [bp-10h]@1

	thisa = this;
	if (*T != this->null_node)
	{
		aatree<_intrnl_var_channel>::FreeTree(this, &(*T)->left, delete_info);
		aatree<_intrnl_var_channel>::FreeTree(thisa, &(*T)->right, delete_info);
		operator delete((*T)->name);
		--thisa->num_nodes;
		if (delete_info)
			operator delete((*T)->info);
		operator delete(*T);
		*T = thisa->null_node;
	}
}

//----- (008D4760) --------------------------------------------------------
_intrnl_var_channel *__thiscall aatree<_intrnl_var_channel>::Search(aatree<_intrnl_var_channel> *this, char *name, aatree<_intrnl_var_channel>::aa_node *cur)
{
	_intrnl_var_channel *result; // eax@2
	aatree<_intrnl_var_channel> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (cur == this->null_node)
	{
		result = 0;
	}
	else
	{
		if (strcmp(name, cur->name))
		{
			if (strcmp(name, cur->name) >= 0)
				result = aatree<_intrnl_var_channel>::Search(thisa, name, cur->right);
			else
				result = aatree<_intrnl_var_channel>::Search(thisa, name, cur->left);
		}
		else
		{
			thisa->cur_visited = cur;
			result = cur->info;
		}
	}
	return result;
}

//----- (008D47F0) --------------------------------------------------------
void __thiscall aatree<intrnl_var>::DeleteAll(aatree<intrnl_var> *this, int delete_info)
{
	aatree<intrnl_var> *v2; // ST08_4@1

	v2 = this;
	aatree<intrnl_var>::FreeTree(this, &this->root, delete_info);
	v2->root = v2->null_node;
}

//----- (008D4820) --------------------------------------------------------
void __thiscall aatree<intrnl_var>::Insert(aatree<intrnl_var> *this, char *name, intrnl_var *info, aatree<intrnl_var>::aa_node **T, aatree<intrnl_var>::aa_node *parent, int info_array_size)
{
	size_t v6; // eax@2
	aatree<intrnl_var> *thisa; // [sp+0h] [bp-Ch]@1

	thisa = this;
	if (*T == this->null_node)
	{
		++this->num_nodes;
		*T = (aatree<intrnl_var>::aa_node *)j__new(0x1Eu, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 189);
		v6 = strlen(name);
		(*T)->name = (char *)j__new(v6 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 190);
		strcpy((*T)->name, name);
		(*T)->info = info;
		(*T)->info_array_size = info_array_size;
		(*T)->right = thisa->null_node;
		(*T)->left = (*T)->right;
		(*T)->parent = parent;
		(*T)->level = 1;
		(*T)->visited = 0;
		return;
	}
	if (strcmp(name, (*T)->name) <= 0)
	{
		aatree<intrnl_var>::Insert(thisa, name, info, &(*T)->left, *T, info_array_size);
	LABEL_8:
		aatree<intrnl_var>::Skew(thisa, T);
		aatree<intrnl_var>::Split(thisa, T);
		return;
	}
	if (strcmp(name, (*T)->name) > 0)
	{
		aatree<intrnl_var>::Insert(thisa, name, info, &(*T)->right, *T, info_array_size);
		goto LABEL_8;
	}
}

//----- (008D49A0) --------------------------------------------------------
void __thiscall aatree<intrnl_var>::ResetParents(aatree<intrnl_var> *this, aatree<intrnl_var>::aa_node *cur, aatree<intrnl_var>::aa_node *parent)
{
	aatree<intrnl_var> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!parent)
		parent = this->null_node;
	if (cur != this->null_node)
	{
		cur->parent = parent;
		aatree<intrnl_var>::ResetParents(this, cur->left, cur);
		aatree<intrnl_var>::ResetParents(thisa, cur->right, cur);
	}
}

//----- (008D4A00) --------------------------------------------------------
int __thiscall aatree<intrnl_var>::Remove(aatree<intrnl_var> *this, char *name, aatree<intrnl_var>::aa_node **T, int delete_info, intrnl_var *info)
{
	size_t v5; // eax@11
	signed int v6; // edx@20
	aatree<intrnl_var> *thisa; // [sp+4h] [bp-18h]@1
	intrnl_var *v9; // [sp+10h] [bp-Ch]@12

	thisa = this;
	if (*T != this->null_node)
	{
		last_ptr = *T;
		if (strcmp(name, (*T)->name) >= 0)
		{
			del_ptr = *T;
			aatree<intrnl_var>::Remove(thisa, name, &(*T)->right, delete_info, info);
		}
		else
		{
			aatree<intrnl_var>::Remove(thisa, name, &(*T)->left, delete_info, info);
		}
		if (*T == last_ptr)
		{
			if (del_ptr == thisa->null_node || strcmp(name, del_ptr->name) || info && del_ptr->info != info)
			{
				item_found = 0;
			}
			else
			{
				operator delete(del_ptr->name);
				if (del_ptr != *T)
				{
					v5 = strlen((*T)->name);
					del_ptr->name = (char *)j__new(v5 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 431);
					strcpy(del_ptr->name, (*T)->name);
					if (delete_info)
					{
						v9 = del_ptr->info;
						if (v9)
							intrnl_var::_vector_deleting_destructor_(v9, 3u);
					}
					del_ptr->info_array_size = (*T)->info_array_size;
					del_ptr->info = (*T)->info;
				}
				*T = (*T)->right;
				del_ptr = thisa->null_node;
				operator delete(last_ptr);
				--thisa->num_nodes;
				item_found = 1;
			}
		}
		else
		{
			if ((*T)->left->level < (*T)->level - 1 || (*T)->right->level < (*T)->level - 1)
			{
				v6 = (*T)->right->level;
				--(*T)->level;
				if (v6 > (*T)->level)
					(*T)->right->level = (*T)->level;
				aatree<intrnl_var>::Skew(thisa, T);
				aatree<intrnl_var>::Skew(thisa, &(*T)->right);
				aatree<intrnl_var>::Skew(thisa, &(*T)->right->right);
				aatree<intrnl_var>::Split(thisa, T);
				aatree<intrnl_var>::Split(thisa, &(*T)->right);
			}
		}
	}
	return 1;
}

//----- (008D4CE0) --------------------------------------------------------
intrnl_var *__thiscall aatree<intrnl_var>::Search(aatree<intrnl_var> *this, char *name, aatree<intrnl_var>::aa_node *cur)
{
	intrnl_var *result; // eax@2
	aatree<intrnl_var> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (cur == this->null_node)
	{
		result = 0;
	}
	else
	{
		if (strcmp(name, cur->name))
		{
			if (strcmp(name, cur->name) >= 0)
				result = aatree<intrnl_var>::Search(thisa, name, cur->right);
			else
				result = aatree<intrnl_var>::Search(thisa, name, cur->left);
		}
		else
		{
			thisa->cur_visited = cur;
			result = cur->info;
		}
	}
	return result;
}

//----- (008D4D70) --------------------------------------------------------
void *__thiscall intrnl_var::_vector_deleting_destructor_(intrnl_var *this, unsigned int __flags)
{
	void *result; // eax@4
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (__flags & 2)
	{
		_vector_destructor_iterator_(
			this,
			0x9Eu,
			*((_DWORD *)this - 1),
			(void(__thiscall *)(void *))intrnl_var::_intrnl_var);
		if (__flags & 1)
			operator delete((char *)thisa - 4);
		result = (char *)thisa - 4;
	}
	else
	{
		intrnl_var::_intrnl_var(this);
		if (__flags & 1)
			operator delete(thisa);
		result = thisa;
	}
	return result;
}

//----- (008D4DF0) --------------------------------------------------------
void __thiscall intrnl_var::_intrnl_var(intrnl_var *this)
{
	aatree<_intrnl_var_channel>::_aatree<_intrnl_var_channel>(&this->channels);
}

//----- (008D4E10) --------------------------------------------------------
void __thiscall aatree<_intrnl_var_channel>::_aatree<_intrnl_var_channel>(aatree<_intrnl_var_channel> *this)
{
	aatree<_intrnl_var_channel>::DeleteAll(this, 1);
}

//----- (008D4E30) --------------------------------------------------------
void __thiscall aatree<_intrnl_var_channel>::Skew(aatree<_intrnl_var_channel> *this, aatree<_intrnl_var_channel>::aa_node **T)
{
	if ((*T)->left->level == (*T)->level)
		*T = aatree<_intrnl_var_channel>::RotateWithLeftChild(this, *T);
}

//----- (008D4E70) --------------------------------------------------------
void __thiscall aatree<_intrnl_var_channel>::Split(aatree<_intrnl_var_channel> *this, aatree<_intrnl_var_channel>::aa_node **T)
{
	if ((*T)->right->right->level == (*T)->level)
	{
		*T = aatree<_intrnl_var_channel>::RotateWithRightChild(this, *T);
		++(*T)->level;
	}
}

//----- (008D4ED0) --------------------------------------------------------
void __thiscall aatree<intrnl_var>::Skew(aatree<intrnl_var> *this, aatree<intrnl_var>::aa_node **T)
{
	if ((*T)->left->level == (*T)->level)
		*T = aatree<intrnl_var>::RotateWithLeftChild(this, *T);
}

//----- (008D4F10) --------------------------------------------------------
void __thiscall aatree<intrnl_var>::Split(aatree<intrnl_var> *this, aatree<intrnl_var>::aa_node **T)
{
	if ((*T)->right->right->level == (*T)->level)
	{
		*T = aatree<intrnl_var>::RotateWithRightChild(this, *T);
		++(*T)->level;
	}
}

//----- (008D4F70) --------------------------------------------------------
void __thiscall aatree<intrnl_var>::FreeTree(aatree<intrnl_var> *this, aatree<intrnl_var>::aa_node **T, int delete_info)
{
	aatree<intrnl_var> *thisa; // [sp+4h] [bp-14h]@1
	intrnl_var *v4; // [sp+10h] [bp-8h]@3

	thisa = this;
	if (*T != this->null_node)
	{
		aatree<intrnl_var>::FreeTree(this, &(*T)->left, delete_info);
		aatree<intrnl_var>::FreeTree(thisa, &(*T)->right, delete_info);
		operator delete((*T)->name);
		--thisa->num_nodes;
		if (delete_info)
		{
			v4 = (*T)->info;
			if (v4)
				intrnl_var::_scalar_deleting_destructor_(v4, 1u);
		}
		operator delete(*T);
		*T = thisa->null_node;
	}
}

//----- (008D5030) --------------------------------------------------------
void *__thiscall intrnl_var::_scalar_deleting_destructor_(intrnl_var *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	intrnl_var::_intrnl_var(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D5060) --------------------------------------------------------
aatree<_intrnl_var_channel>::aa_node *__thiscall aatree<_intrnl_var_channel>::RotateWithLeftChild(aatree<_intrnl_var_channel> *this, aatree<_intrnl_var_channel>::aa_node *T)
{
	aatree<_intrnl_var_channel>::aa_node *v2; // ST04_4@1

	v2 = T->left;
	T->left = v2->right;
	v2->right->parent = T;
	v2->right = T;
	v2->parent = T->parent;
	T->parent = v2;
	return v2;
}

//----- (008D50C0) --------------------------------------------------------
aatree<_intrnl_var_channel>::aa_node *__thiscall aatree<_intrnl_var_channel>::RotateWithRightChild(aatree<_intrnl_var_channel> *this, aatree<_intrnl_var_channel>::aa_node *T)
{
	aatree<_intrnl_var_channel>::aa_node *v2; // ST04_4@1

	v2 = T->right;
	T->right = v2->left;
	v2->left->parent = T;
	v2->left = T;
	v2->parent = T->parent;
	T->parent = v2;
	return v2;
}

//----- (008D5120) --------------------------------------------------------
aatree<intrnl_var>::aa_node *__thiscall aatree<intrnl_var>::RotateWithLeftChild(aatree<intrnl_var> *this, aatree<intrnl_var>::aa_node *T)
{
	aatree<intrnl_var>::aa_node *v2; // ST04_4@1

	v2 = T->left;
	T->left = v2->right;
	v2->right->parent = T;
	v2->right = T;
	v2->parent = T->parent;
	T->parent = v2;
	return v2;
}

//----- (008D5180) --------------------------------------------------------
aatree<intrnl_var>::aa_node *__thiscall aatree<intrnl_var>::RotateWithRightChild(aatree<intrnl_var> *this, aatree<intrnl_var>::aa_node *T)
{
	aatree<intrnl_var>::aa_node *v2; // ST04_4@1

	v2 = T->right;
	T->right = v2->left;
	v2->left->parent = T;
	v2->left = T;
	v2->parent = T->parent;
	T->parent = v2;
	return v2;
}








//----- (008D6210) --------------------------------------------------------
int __cdecl _E6_55()
{
	_E3_49();
	return _E5_38();
}

//----- (008D621F) --------------------------------------------------------
void __cdecl _E3_49()
{
	aatree<short>::aatree<short>(&g_input_codes);
}

//----- (008D622E) --------------------------------------------------------
int __cdecl _E5_38()
{
	return atexit(_E4_54);
}

//----- (008D6240) --------------------------------------------------------
void __cdecl _E4_54()
{
	aatree<short>::_aatree<short>(&g_input_codes);
}

//----- (008D624F) --------------------------------------------------------
int __cdecl _E11_59()
{
	_E8_64();
	return _E10_55();
}

//----- (008D625E) --------------------------------------------------------
void __cdecl _E8_64()
{
	_vector_constructor_iterator_(&g_input_controls, 0x10u, 3, (void(__thiscall *)(void *))aatree<char>::aatree<char>);
}

//----- (008D6276) --------------------------------------------------------
int __cdecl _E10_55()
{
	return atexit(_E9_70);
}

//----- (008D6288) --------------------------------------------------------
void __cdecl _E9_70()
{
	_vector_destructor_iterator_(&g_input_controls, 0x10u, 3, (void(__thiscall *)(void *))aatree<char>::_aatree<char>);
}

//----- (008D62A0) --------------------------------------------------------
int __cdecl _E16_22()
{
	_E13_53();
	return _E15_33();
}

//----- (008D62AF) --------------------------------------------------------
void __cdecl _E13_53()
{
	aatree<unsigned_char>::aatree<unsigned_char>(&g_input_down);
}

//----- (008D62BE) --------------------------------------------------------
int __cdecl _E15_33()
{
	return atexit(_E14_56);
}

//----- (008D62D0) --------------------------------------------------------
void __cdecl _E14_56()
{
	aatree<unsigned_char>::_aatree<unsigned_char>(&g_input_down);
}

//----- (008D62DF) --------------------------------------------------------
void __cdecl _E19_20()
{
	_E18_19();
}

//----- (008D62E9) --------------------------------------------------------
void __cdecl _E18_19()
{
	cContainerDList<sControlDown_0>::cContainerDList<sControlDown_0>(&g_ctrldown_list);
}

//----- (008D62F8) --------------------------------------------------------
int __cdecl _E24_10()
{
	_E21_14();
	return _E23_10();
}

//----- (008D6307) --------------------------------------------------------
void __cdecl _E21_14()
{
	cCmdCtrlHash::cCmdCtrlHash(&g_CmdCtrlHash);
}

//----- (008D6316) --------------------------------------------------------
int __cdecl _E23_10()
{
	return atexit(_E22_11);
}

//----- (008D6328) --------------------------------------------------------
void __cdecl _E22_11()
{
	cCmdCtrlHash::_cCmdCtrlHash(&g_CmdCtrlHash);
}

//----- (008D96B7) --------------------------------------------------------
void __thiscall cIBJoyAxisProcess::cIBJoyAxisProcess(cIBJoyAxisProcess *this)
{
	this->vfptr = (cIBJoyAxisProcessVtbl *)cIBJoyAxisProcess::_vftable_;
	*(_QWORD *)&this->m_deadzone_x = 0i64;
	*(_QWORD *)&this->m_deadzone_y = 0i64;
	*(_QWORD *)&this->m_deadzone_z = 0i64;
	*(_QWORD *)&this->m_deadzone_r = 0i64;
}
// 9A7B20: using guessed type int (__stdcall *cIBJoyAxisProcess___vftable_[2])(int x, int y);

//----- (008D9712) --------------------------------------------------------
void __thiscall cIBJoyAxisProcess::ProcessXY(cIBJoyAxisProcess *this, long double *x, long double *y)
{
	cIBJoyAxisProcess *v3; // ST0C_4@1

	v3 = this;
	cIBJoyAxisProcess::ApplyDeadzone(this, x, this->m_deadzone_x);
	cIBJoyAxisProcess::ApplyDeadzone(v3, y, v3->m_deadzone_y);
}

//----- (008D974D) --------------------------------------------------------
void __thiscall cIBJoyAxisProcess::ProcessZR(cIBJoyAxisProcess *this, long double *z, long double *r)
{
	cIBJoyAxisProcess *v3; // ST0C_4@1

	v3 = this;
	cIBJoyAxisProcess::ApplyDeadzone(this, z, this->m_deadzone_z);
	cIBJoyAxisProcess::ApplyDeadzone(v3, r, v3->m_deadzone_r);
}

//----- (008D9788) --------------------------------------------------------
void __thiscall cIBJoyAxisProcess::ApplyDeadzone(cIBJoyAxisProcess *this, long double *axis, long double deadzone)
{
	double v3; // [sp+0h] [bp-1Ch]@4
	double axis_abs; // [sp+Ch] [bp-10h]@1
	double axis_absa; // [sp+Ch] [bp-10h]@3

	axis_abs = fabs(*((_DWORD *)axis + 1), *axis);
	if (axis_abs >= deadzone)
	{
		axis_absa = (axis_abs - deadzone) * 1.0 / (1.0 - deadzone);
		if (*axis >= 0.0)
			v3 = axis_absa;
		else
			v3 = -axis_absa;
		*(_QWORD *)axis = *(_QWORD *)&v3;
	}
	else
	{
		*(_QWORD *)axis = 0i64;
	}
}

//----- (008D9820) --------------------------------------------------------
void __thiscall cContainerDList<sControlDown_0>::cContainerDList<sControlDown_0>(cContainerDList<sControlDown, 0> *this)
{
	cDList<cContDListNode<sControlDown_0>_0>::cDList<cContDListNode<sControlDown_0>_0>(&this->baseclass_0);
}

//----- (008D9840) --------------------------------------------------------
void __thiscall cDList<cContDListNode<sControlDown_0>_0>::cDList<cContDListNode<sControlDown_0>_0>(cDList<cContDListNode<sControlDown, 0>, 0> *this)
{
	cDListBase::cDListBase(&this->baseclass_0);
}

//----- (008D9860) --------------------------------------------------------
void __thiscall cCmdCtrlHash::_cCmdCtrlHash(cCmdCtrlHash *this)
{
	cStrIHashSet<sCmdCtrlEntry__>::_cStrIHashSet<sCmdCtrlEntry__>(&this->baseclass_0);
}

//----- (008D9880) --------------------------------------------------------
void __thiscall cCmdCtrlHash::cCmdCtrlHash(cCmdCtrlHash *this)
{
	cCmdCtrlHash *v1; // ST04_4@1

	v1 = this;
	cStrIHashSet<sCmdCtrlEntry__>::cStrIHashSet<sCmdCtrlEntry__>(&this->baseclass_0, 0x65u);
	v1->baseclass_0.baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cCmdCtrlHash::_vftable_;
}
// 9A7B00: using guessed type int (__stdcall *cCmdCtrlHash___vftable_)(int __flags);

//----- (008D98B0) --------------------------------------------------------
tHashSetKey__ *__thiscall cCmdCtrlHash::GetKey(cCmdCtrlHash *this, tHashSetNode__ *pItem)
{
	return (tHashSetKey__ *)cAnsiStr::operator char_const__((cAnsiStr *)pItem);
}

//----- (008D98D0) --------------------------------------------------------
void __thiscall cCmdCtrlHash::DestroyAll(cCmdCtrlHash *this)
{
	cCmdCtrlHash *thisa; // [sp+8h] [bp-30h]@1
	sHashSetChunk *pNext; // [sp+20h] [bp-18h]@6
	sHashSetChunk *p; // [sp+24h] [bp-14h]@4
	cContDListNode<cAnsiStr, 0> *pListNode; // [sp+28h] [bp-10h]@7
	cDList<cContDListNode<cAnsiStr, 0>, 0> *pList; // [sp+2Ch] [bp-Ch]@6
	unsigned int i; // [sp+30h] [bp-8h]@2
	sCmdCtrlEntry *pEntry; // [sp+34h] [bp-4h]@6

	thisa = this;
	if (this->baseclass_0.baseclass_0.baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.baseclass_0.baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.baseclass_0.baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				pEntry = (sCmdCtrlEntry *)p->node;
				pList = (cDList<cContDListNode<cAnsiStr, 0>, 0> *)&p->node[3];
				while (1)
				{
					pListNode = cDList<cContDListNode<cAnsiStr_0>_0>::GetFirst(pList);
					if (!pListNode)
						break;
					if (pListNode)
						cContDListNode<cAnsiStr_0>::_scalar_deleting_destructor_(pListNode, 1u);
				}
				if (pEntry)
					sCmdCtrlEntry::_scalar_deleting_destructor_(pEntry, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.baseclass_0.baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.baseclass_0.baseclass_0.m_nItems = 0;
	}
}

//----- (008D99F0) --------------------------------------------------------
void *__thiscall cContDListNode<cAnsiStr_0>::_scalar_deleting_destructor_(cContDListNode<cAnsiStr, 0> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cContDListNode<cAnsiStr_0>::_cContDListNode<cAnsiStr_0>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D9A20) --------------------------------------------------------
void *__thiscall sCmdCtrlEntry::_scalar_deleting_destructor_(sCmdCtrlEntry *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	sCmdCtrlEntry::_sCmdCtrlEntry(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D9A50) --------------------------------------------------------
void __thiscall cContDListNode<cAnsiStr_0>::_cContDListNode<cAnsiStr_0>(cContDListNode<cAnsiStr, 0> *this)
{
	cAnsiStr::_cAnsiStr(&this->item);
}

//----- (008D9A70) --------------------------------------------------------
void __thiscall sCmdCtrlEntry::_sCmdCtrlEntry(sCmdCtrlEntry *this)
{
	cAnsiStr::_cAnsiStr(&this->cmd);
}

//----- (008D9A90) --------------------------------------------------------
void __thiscall cStrIHashSet<sCmdCtrlEntry__>::_cStrIHashSet<sCmdCtrlEntry__>(cStrIHashSet<sCmdCtrlEntry *> *this)
{
	cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::_cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>(&this->baseclass_0);
}

//----- (008D9AB0) --------------------------------------------------------
void *__thiscall cCmdCtrlHash::_scalar_deleting_destructor_(cCmdCtrlHash *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cCmdCtrlHash::_cCmdCtrlHash(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D9AE0) --------------------------------------------------------
void __thiscall cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::_cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>(cHashSet<sCmdCtrlEntry *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSetBase::_cHashSetBase(&this->baseclass_0);
}

//----- (008D9B00) --------------------------------------------------------
void __thiscall sCmdCtrlEntry::sCmdCtrlEntry(sCmdCtrlEntry *this)
{
	sCmdCtrlEntry *v1; // ST00_4@1

	v1 = this;
	cAnsiStr::cAnsiStr(&this->cmd);
	cContainerDList<cAnsiStr_0>::cContainerDList<cAnsiStr_0>(&v1->ctrlList);
}

//----- (008D9B30) --------------------------------------------------------
void __thiscall cContDListNode<cAnsiStr_0>::cContDListNode<cAnsiStr_0>(cContDListNode<cAnsiStr, 0> *this)
{
	cContDListNode<cAnsiStr, 0> *v1; // ST00_4@1

	v1 = this;
	cDListNode<cContDListNode<cAnsiStr_0>_0>::cDListNode<cContDListNode<cAnsiStr_0>_0>(&this->baseclass_0);
	cAnsiStr::cAnsiStr(&v1->item);
}

//----- (008D9B60) --------------------------------------------------------
void __thiscall cContainerDList<cAnsiStr_0>::cContainerDList<cAnsiStr_0>(cContainerDList<cAnsiStr, 0> *this)
{
	cDList<cContDListNode<cAnsiStr_0>_0>::cDList<cContDListNode<cAnsiStr_0>_0>(&this->baseclass_0);
}

//----- (008D9B80) --------------------------------------------------------
void __thiscall cDListNode<cContDListNode<cAnsiStr_0>_0>::cDListNode<cContDListNode<cAnsiStr_0>_0>(cDListNode<cContDListNode<cAnsiStr, 0>, 0> *this)
{
	cDListNodeBase::cDListNodeBase(&this->baseclass_0);
}

//----- (008D9BA0) --------------------------------------------------------
void __thiscall cDList<cContDListNode<cAnsiStr_0>_0>::cDList<cContDListNode<cAnsiStr_0>_0>(cDList<cContDListNode<cAnsiStr, 0>, 0> *this)
{
	cDListBase::cDListBase(&this->baseclass_0);
}

//----- (008D9BC0) --------------------------------------------------------
void __thiscall cContDListNode<sControlDown_0>::cContDListNode<sControlDown_0>(cContDListNode<sControlDown, 0> *this)
{
	cContDListNode<sControlDown, 0> *v1; // ST00_4@1

	v1 = this;
	cDListNode<cContDListNode<sControlDown_0>_0>::cDListNode<cContDListNode<sControlDown_0>_0>(&this->baseclass_0);
	sControlDown::sControlDown(&v1->item);
}

//----- (008D9BF0) --------------------------------------------------------
void *__thiscall cContDListNode<sControlDown_0>::_scalar_deleting_destructor_(cContDListNode<sControlDown, 0> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cContDListNode<sControlDown_0>::_cContDListNode<sControlDown_0>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D9C20) --------------------------------------------------------
void __thiscall cDListNode<cContDListNode<sControlDown_0>_0>::cDListNode<cContDListNode<sControlDown_0>_0>(cDListNode<cContDListNode<sControlDown, 0>, 0> *this)
{
	cDListNodeBase::cDListNodeBase(&this->baseclass_0);
}

//----- (008D9C40) --------------------------------------------------------
void __thiscall sControlDown::sControlDown(sControlDown *this)
{
	cAnsiStr::cAnsiStr(&this->control);
}

//----- (008D9C60) --------------------------------------------------------
void __thiscall cContDListNode<sControlDown_0>::_cContDListNode<sControlDown_0>(cContDListNode<sControlDown, 0> *this)
{
	sControlDown::_sControlDown(&this->item);
}

//----- (008D9C80) --------------------------------------------------------
void __thiscall sControlDown::_sControlDown(sControlDown *this)
{
	cAnsiStr::_cAnsiStr(&this->control);
}

//----- (008D9CA0) --------------------------------------------------------
void __thiscall cStrIHashSet<sCmdCtrlEntry__>::cStrIHashSet<sCmdCtrlEntry__>(cStrIHashSet<sCmdCtrlEntry *> *this, unsigned int n)
{
	cStrIHashSet<sCmdCtrlEntry *> *v2; // ST04_4@1

	v2 = this;
	cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>(
		&this->baseclass_0,
		n);
	v2->baseclass_0.baseclass_0.vfptr = (cHashSetBaseVtbl *)&cStrIHashSet<sCmdCtrlEntry__>::_vftable_;
}
// 9A7B28: using guessed type int (__stdcall *cStrIHashSet_sCmdCtrlEntry _____vftable_)(int __flags);

//----- (008D9CD0) --------------------------------------------------------
void *__thiscall cStrIHashSet<sCmdCtrlEntry__>::_vector_deleting_destructor_(cStrIHashSet<sCmdCtrlEntry *> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cStrIHashSet<sCmdCtrlEntry__>::_cStrIHashSet<sCmdCtrlEntry__>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D9D00) --------------------------------------------------------
void __thiscall cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>(cHashSet<sCmdCtrlEntry *, char const *, cCaselessStringHashFuncs> *this, unsigned int n)
{
	cHashSet<sCmdCtrlEntry *, char const *, cCaselessStringHashFuncs> *v2; // ST14_4@1

	v2 = this;
	cHashSetBase::cHashSetBase(&this->baseclass_0, n);
	v2->baseclass_0.vfptr = (cHashSetBaseVtbl *)&cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::_vftable_;
}
// 9A7B48: using guessed type int (__stdcall *cHashSet_sCmdCtrlEntry __char const __cCaselessStringHashFuncs____vftable_)(int __flags);

//----- (008D9D70) --------------------------------------------------------
void *__thiscall cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::_vector_deleting_destructor_(cHashSet<sCmdCtrlEntry *, char const *, cCaselessStringHashFuncs> *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::_cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008D9DA0) --------------------------------------------------------
void __thiscall aatree<char>::aatree<char>(aatree<char> *this)
{
	aatree<char> *v1; // ST0C_4@1
	void *v2; // eax@1

	v1 = this;
	v2 = j__new(0x1Eu, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 70);
	v1->null_node = (aatree<char>::aa_node *)v2;
	v1->root = (aatree<char>::aa_node *)v2;
	v1->num_nodes = 0;
	v1->null_node->level = 0;
	v1->null_node->name = 0;
	v1->null_node->info = 0;
	v1->root = v1->null_node;
	v1->null_node->right = v1->root;
	v1->null_node->left = v1->null_node->right;
}

//----- (008D9E40) --------------------------------------------------------
void __thiscall aatree<char>::_aatree<char>(aatree<char> *this)
{
	aatree<char>::DeleteAll(this, 1);
}

//----- (008D9E60) --------------------------------------------------------
void __thiscall aatree<char>::Add(aatree<char> *this, char *name, char *info, int info_array_size)
{
	aatree<char>::Insert(this, name, info, &this->root, this->null_node, info_array_size);
}

//----- (008D9E90) --------------------------------------------------------
int __thiscall aatree<char>::Delete(aatree<char> *this, char *name, int delete_info, char *info)
{
	aatree<char> *v4; // ST10_4@1
	int v5; // ST14_4@1

	v4 = this;
	v5 = aatree<char>::Remove(this, name, &this->root, delete_info, info);
	aatree<char>::ResetParents(v4, v4->root, 0);
	return v5;
}

//----- (008D9EE0) --------------------------------------------------------
char *__thiscall aatree<char>::Find(aatree<char> *this, char *name)
{
	return aatree<char>::Search(this, name, this->root);
}

//----- (008D9F00) --------------------------------------------------------
void __thiscall aatree<char>::ChangeInfo(aatree<char> *this, char *name, char *info, int info_array_size)
{
	aatree<char>::ChangeNodeInfo(this, name, info, this->root, info_array_size);
}

//----- (008D9F30) --------------------------------------------------------
void __thiscall aatree<char>::ResetVisited(aatree<char> *this, aatree<char>::aa_node *cur)
{
	aatree<char> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!cur)
	{
		cur = this->root;
		this->cur_visited = this->root;
	}
	if (cur != this->null_node)
	{
		aatree<char>::ResetVisited(this, cur->left);
		aatree<char>::ResetVisited(thisa, cur->right);
		cur->visited = 0;
	}
}

//----- (008D9F90) --------------------------------------------------------
char *__thiscall aatree<char>::GetNextInOrder(aatree<char> *this, char *str)
{
	char *result; // eax@2
	aatree<char> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->cur_visited == this->null_node)
	{
		result = 0;
	}
	else
	{
		if (this->cur_visited->left == this->null_node || this->cur_visited->left->visited)
		{
			if (this->cur_visited->visited)
			{
				if (this->cur_visited->right == this->null_node || this->cur_visited->right->visited)
				{
					this->cur_visited = this->cur_visited->parent;
					result = aatree<char>::GetNextInOrder(this, str);
				}
				else
				{
					this->cur_visited = this->cur_visited->right;
					result = aatree<char>::GetNextInOrder(this, str);
				}
			}
			else
			{
				this->cur_visited->visited = 1;
				if (str)
					strcpy(str, this->cur_visited->name);
				result = thisa->cur_visited->info;
			}
		}
		else
		{
			this->cur_visited = this->cur_visited->left;
			result = aatree<char>::GetNextInOrder(this, str);
		}
	}
	return result;
}

//----- (008DA090) --------------------------------------------------------
void __thiscall aatree<short>::aatree<short>(aatree<short> *this)
{
	aatree<short> *v1; // ST0C_4@1
	void *v2; // eax@1

	v1 = this;
	v2 = j__new(0x1Eu, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 70);
	v1->null_node = (aatree<short>::aa_node *)v2;
	v1->root = (aatree<short>::aa_node *)v2;
	v1->num_nodes = 0;
	v1->null_node->level = 0;
	v1->null_node->name = 0;
	v1->null_node->info = 0;
	v1->root = v1->null_node;
	v1->null_node->right = v1->root;
	v1->null_node->left = v1->null_node->right;
}

//----- (008DA130) --------------------------------------------------------
void __thiscall aatree<short>::_aatree<short>(aatree<short> *this)
{
	aatree<short>::DeleteAll(this, 1);
}

//----- (008DA150) --------------------------------------------------------
void __thiscall aatree<short>::Add(aatree<short> *this, char *name, __int16 *info, int info_array_size)
{
	aatree<short>::Insert(this, name, info, &this->root, this->null_node, info_array_size);
}

//----- (008DA180) --------------------------------------------------------
__int16 *__thiscall aatree<short>::Find(aatree<short> *this, char *name)
{
	return aatree<short>::Search(this, name, this->root);
}

//----- (008DA1A0) --------------------------------------------------------
int __thiscall aatree<short>::GetNumNodes(aatree<short> *this)
{
	return this->num_nodes;
}

//----- (008DA1B0) --------------------------------------------------------
void __thiscall aatree<unsigned_char>::aatree<unsigned_char>(aatree<unsigned char> *this)
{
	aatree<unsigned char> *v1; // ST0C_4@1
	void *v2; // eax@1

	v1 = this;
	v2 = j__new(0x1Eu, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 70);
	v1->null_node = (aatree<unsigned char>::aa_node *)v2;
	v1->root = (aatree<unsigned char>::aa_node *)v2;
	v1->num_nodes = 0;
	v1->null_node->level = 0;
	v1->null_node->name = 0;
	v1->null_node->info = 0;
	v1->root = v1->null_node;
	v1->null_node->right = v1->root;
	v1->null_node->left = v1->null_node->right;
}

//----- (008DA250) --------------------------------------------------------
void __thiscall aatree<unsigned_char>::_aatree<unsigned_char>(aatree<unsigned char> *this)
{
	aatree<unsigned_char>::DeleteAll(this, 1);
}

//----- (008DA270) --------------------------------------------------------
void __thiscall aatree<unsigned_char>::Add(aatree<unsigned char> *this, char *name, char *info, int info_array_size)
{
	aatree<unsigned_char>::Insert(this, name, info, &this->root, this->null_node, info_array_size);
}

//----- (008DA2A0) --------------------------------------------------------
int __thiscall aatree<unsigned_char>::Delete(aatree<unsigned char> *this, char *name, int delete_info, char *info)
{
	aatree<unsigned char> *v4; // ST10_4@1
	int v5; // ST14_4@1

	v4 = this;
	v5 = aatree<unsigned_char>::Remove(this, name, &this->root, delete_info, info);
	aatree<unsigned_char>::ResetParents(v4, v4->root, 0);
	return v5;
}

//----- (008DA2F0) --------------------------------------------------------
char *__thiscall aatree<unsigned_char>::Find(aatree<unsigned char> *this, char *name)
{
	return aatree<unsigned_char>::Search(this, name, this->root);
}

//----- (008DA310) --------------------------------------------------------
void __thiscall aatree<unsigned_char>::ResetVisited(aatree<unsigned char> *this, aatree<unsigned char>::aa_node *cur)
{
	aatree<unsigned char> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!cur)
	{
		cur = this->root;
		this->cur_visited = this->root;
	}
	if (cur != this->null_node)
	{
		aatree<unsigned_char>::ResetVisited(this, cur->left);
		aatree<unsigned_char>::ResetVisited(thisa, cur->right);
		cur->visited = 0;
	}
}

//----- (008DA370) --------------------------------------------------------
char *__thiscall aatree<unsigned_char>::GetNextInOrder(aatree<unsigned char> *this, char *str)
{
	char *result; // eax@2
	aatree<unsigned char> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (this->cur_visited == this->null_node)
	{
		result = 0;
	}
	else
	{
		if (this->cur_visited->left == this->null_node || this->cur_visited->left->visited)
		{
			if (this->cur_visited->visited)
			{
				if (this->cur_visited->right == this->null_node || this->cur_visited->right->visited)
				{
					this->cur_visited = this->cur_visited->parent;
					result = aatree<unsigned_char>::GetNextInOrder(this, str);
				}
				else
				{
					this->cur_visited = this->cur_visited->right;
					result = aatree<unsigned_char>::GetNextInOrder(this, str);
				}
			}
			else
			{
				this->cur_visited->visited = 1;
				if (str)
					strcpy(str, this->cur_visited->name);
				result = thisa->cur_visited->info;
			}
		}
		else
		{
			this->cur_visited = this->cur_visited->left;
			result = aatree<unsigned_char>::GetNextInOrder(this, str);
		}
	}
	return result;
}

//----- (008DA470) --------------------------------------------------------
void __thiscall cDList<cContDListNode<sControlDown_0>_0>::Prepend(cDList<cContDListNode<sControlDown, 0>, 0> *this, cContDListNode<sControlDown, 0> *Node)
{
	cDListBase::Prepend(&this->baseclass_0, &Node->baseclass_0.baseclass_0);
}

//----- (008DA490) --------------------------------------------------------
cContDListNode<sControlDown, 0> *__thiscall cDList<cContDListNode<sControlDown_0>_0>::Remove(cDList<cContDListNode<sControlDown, 0>, 0> *this, cContDListNode<sControlDown, 0> *Node)
{
	return (cContDListNode<sControlDown, 0> *)cDListBase::Remove(&this->baseclass_0, &Node->baseclass_0.baseclass_0);
}

//----- (008DA4B0) --------------------------------------------------------
cContDListNode<sControlDown, 0> *__thiscall cDList<cContDListNode<sControlDown_0>_0>::GetFirst(cDList<cContDListNode<sControlDown, 0>, 0> *this)
{
	return (cContDListNode<sControlDown, 0> *)cDListBase::GetFirst(&this->baseclass_0);
}

//----- (008DA4D0) --------------------------------------------------------
void __thiscall cDList<cContDListNode<cAnsiStr_0>_0>::Append(cDList<cContDListNode<cAnsiStr, 0>, 0> *this, cContDListNode<cAnsiStr, 0> *Node)
{
	cDListBase::Append(&this->baseclass_0, &Node->baseclass_0.baseclass_0);
}

//----- (008DA4F0) --------------------------------------------------------
cContDListNode<cAnsiStr, 0> *__thiscall cDList<cContDListNode<cAnsiStr_0>_0>::Remove(cDList<cContDListNode<cAnsiStr, 0>, 0> *this, cContDListNode<cAnsiStr, 0> *Node)
{
	return (cContDListNode<cAnsiStr, 0> *)cDListBase::Remove(&this->baseclass_0, &Node->baseclass_0.baseclass_0);
}

//----- (008DA510) --------------------------------------------------------
cContDListNode<cAnsiStr, 0> *__thiscall cDList<cContDListNode<cAnsiStr_0>_0>::GetFirst(cDList<cContDListNode<cAnsiStr, 0>, 0> *this)
{
	return (cContDListNode<cAnsiStr, 0> *)cDListBase::GetFirst(&this->baseclass_0);
}

//----- (008DA530) --------------------------------------------------------
sCmdCtrlEntry *__thiscall cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::Insert(cHashSet<sCmdCtrlEntry *, char const *, cCaselessStringHashFuncs> *this, sCmdCtrlEntry *node)
{
	return (sCmdCtrlEntry *)cHashSetBase::Insert(&this->baseclass_0, (tHashSetNode__ *)node);
}

//----- (008DA550) --------------------------------------------------------
sCmdCtrlEntry *__thiscall cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::Search(cHashSet<sCmdCtrlEntry *, char const *, cCaselessStringHashFuncs> *this, const char *key)
{
	return (sCmdCtrlEntry *)cHashSetBase::Search(&this->baseclass_0, (tHashSetKey__ *)key);
}

//----- (008DA570) --------------------------------------------------------
void __thiscall cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::DestroyAll(cHashSet<sCmdCtrlEntry *, char const *, cCaselessStringHashFuncs> *this)
{
	cHashSet<sCmdCtrlEntry *, char const *, cCaselessStringHashFuncs> *thisa; // [sp+4h] [bp-1Ch]@1
	sHashSetChunk *pNext; // [sp+14h] [bp-Ch]@6
	sHashSetChunk *p; // [sp+18h] [bp-8h]@4
	unsigned int i; // [sp+1Ch] [bp-4h]@2

	thisa = this;
	if (this->baseclass_0.m_nItems)
	{
		for (i = 0; i < thisa->baseclass_0.m_nPts; ++i)
		{
			for (p = thisa->baseclass_0.m_Table[i]; p; p = pNext)
			{
				pNext = p->pNext;
				if (p->node)
					sCmdCtrlEntry::_scalar_deleting_destructor_((sCmdCtrlEntry *)p->node, 1u);
				sHashSetChunk::operator delete(p, 8u);
			}
			thisa->baseclass_0.m_Table[i] = 0;
		}
		thisa->baseclass_0.m_nItems = 0;
	}
}

//----- (008DA630) --------------------------------------------------------
int __thiscall cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::IsEqual(cHashSet<sCmdCtrlEntry *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k1, tHashSetKey__ *k2)
{
	return cCaselessStringHashFuncs::IsEqual((const char *)k1, (const char *)k2);
}

//----- (008DA650) --------------------------------------------------------
unsigned int __thiscall cHashSet<sCmdCtrlEntry___char_const___cCaselessStringHashFuncs>::Hash(cHashSet<sCmdCtrlEntry *, char const *, cCaselessStringHashFuncs> *this, tHashSetKey__ *k)
{
	return cCaselessStringHashFuncs::Hash((const char *)k);
}

//----- (008DA670) --------------------------------------------------------
cContDListNode<cAnsiStr, 0> *__thiscall cDListNode<cContDListNode<cAnsiStr_0>_0>::GetNext(cDListNode<cContDListNode<cAnsiStr, 0>, 0> *this)
{
	return (cContDListNode<cAnsiStr, 0> *)cDListNodeBase::GetNext(&this->baseclass_0);
}

//----- (008DA690) --------------------------------------------------------
cContDListNode<sControlDown, 0> *__thiscall cDListNode<cContDListNode<sControlDown_0>_0>::GetNext(cDListNode<cContDListNode<sControlDown, 0>, 0> *this)
{
	return (cContDListNode<sControlDown, 0> *)cDListNodeBase::GetNext(&this->baseclass_0);
}

//----- (008DA6B0) --------------------------------------------------------
void __thiscall aatree<char>::DeleteAll(aatree<char> *this, int delete_info)
{
	aatree<char> *v2; // ST08_4@1

	v2 = this;
	aatree<char>::FreeTree(this, &this->root, delete_info);
	v2->root = v2->null_node;
}

//----- (008DA6E0) --------------------------------------------------------
void __thiscall aatree<char>::Insert(aatree<char> *this, char *name, char *info, aatree<char>::aa_node **T, aatree<char>::aa_node *parent, int info_array_size)
{
	size_t v6; // eax@2
	aatree<char> *thisa; // [sp+0h] [bp-Ch]@1

	thisa = this;
	if (*T == this->null_node)
	{
		++this->num_nodes;
		*T = (aatree<char>::aa_node *)j__new(0x1Eu, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 189);
		v6 = strlen(name);
		(*T)->name = (char *)j__new(v6 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 190);
		strcpy((*T)->name, name);
		(*T)->info = info;
		(*T)->info_array_size = info_array_size;
		(*T)->right = thisa->null_node;
		(*T)->left = (*T)->right;
		(*T)->parent = parent;
		(*T)->level = 1;
		(*T)->visited = 0;
		return;
	}
	if (strcmp(name, (*T)->name) <= 0)
	{
		aatree<char>::Insert(thisa, name, info, &(*T)->left, *T, info_array_size);
	LABEL_8:
		aatree<char>::Skew(thisa, T);
		aatree<char>::Split(thisa, T);
		return;
	}
	if (strcmp(name, (*T)->name) > 0)
	{
		aatree<char>::Insert(thisa, name, info, &(*T)->right, *T, info_array_size);
		goto LABEL_8;
	}
}

//----- (008DA860) --------------------------------------------------------
void __thiscall aatree<char>::ChangeNodeInfo(aatree<char> *this, char *name, char *info, aatree<char>::aa_node *cur, int info_array_size)
{
	aatree<char> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (cur != this->null_node)
	{
		if (strcmp(name, cur->name))
		{
			if (strcmp(name, cur->name) >= 0)
				aatree<char>::ChangeNodeInfo(thisa, name, info, cur->right, info_array_size);
			else
				aatree<char>::ChangeNodeInfo(thisa, name, info, cur->left, info_array_size);
		}
		else
		{
			cur->info = info;
			cur->info_array_size = info_array_size;
		}
	}
}

//----- (008DA900) --------------------------------------------------------
void __thiscall aatree<char>::ResetParents(aatree<char> *this, aatree<char>::aa_node *cur, aatree<char>::aa_node *parent)
{
	aatree<char> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!parent)
		parent = this->null_node;
	if (cur != this->null_node)
	{
		cur->parent = parent;
		aatree<char>::ResetParents(this, cur->left, cur);
		aatree<char>::ResetParents(thisa, cur->right, cur);
	}
}

//----- (008DA960) --------------------------------------------------------
int __thiscall aatree<char>::Remove(aatree<char> *this, char *name, aatree<char>::aa_node **T, int delete_info, char *info)
{
	size_t v5; // eax@11
	signed int v6; // edx@19
	aatree<char> *thisa; // [sp+0h] [bp-14h]@1

	thisa = this;
	if (*T != this->null_node)
	{
		last_ptr = *T;
		if (strcmp(name, (*T)->name) >= 0)
		{
			del_ptr = *T;
			aatree<char>::Remove(thisa, name, &(*T)->right, delete_info, info);
		}
		else
		{
			aatree<char>::Remove(thisa, name, &(*T)->left, delete_info, info);
		}
		if (*T == last_ptr)
		{
			if (del_ptr == thisa->null_node || strcmp(name, del_ptr->name) || info && del_ptr->info != info)
			{
				item_found = 0;
			}
			else
			{
				operator delete(del_ptr->name);
				if (del_ptr != *T)
				{
					v5 = strlen((*T)->name);
					del_ptr->name = (char *)j__new(v5 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 431);
					strcpy(del_ptr->name, (*T)->name);
					if (delete_info)
						operator delete(del_ptr->info);
					del_ptr->info_array_size = (*T)->info_array_size;
					del_ptr->info = (*T)->info;
				}
				*T = (*T)->right;
				del_ptr = thisa->null_node;
				operator delete(last_ptr);
				--thisa->num_nodes;
				item_found = 1;
			}
		}
		else
		{
			if ((*T)->left->level < (*T)->level - 1 || (*T)->right->level < (*T)->level - 1)
			{
				v6 = (*T)->right->level;
				--(*T)->level;
				if (v6 > (*T)->level)
					(*T)->right->level = (*T)->level;
				aatree<char>::Skew(thisa, T);
				aatree<char>::Skew(thisa, &(*T)->right);
				aatree<char>::Skew(thisa, &(*T)->right->right);
				aatree<char>::Split(thisa, T);
				aatree<char>::Split(thisa, &(*T)->right);
			}
		}
	}
	return 1;
}

//----- (008DAC20) --------------------------------------------------------
char *__thiscall aatree<char>::Search(aatree<char> *this, char *name, aatree<char>::aa_node *cur)
{
	char *result; // eax@2
	aatree<char> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (cur == this->null_node)
	{
		result = 0;
	}
	else
	{
		if (strcmp(name, cur->name))
		{
			if (strcmp(name, cur->name) >= 0)
				result = aatree<char>::Search(thisa, name, cur->right);
			else
				result = aatree<char>::Search(thisa, name, cur->left);
		}
		else
		{
			thisa->cur_visited = cur;
			result = cur->info;
		}
	}
	return result;
}

//----- (008DACB0) --------------------------------------------------------
void __thiscall aatree<short>::DeleteAll(aatree<short> *this, int delete_info)
{
	aatree<short> *v2; // ST08_4@1

	v2 = this;
	aatree<short>::FreeTree(this, &this->root, delete_info);
	v2->root = v2->null_node;
}

//----- (008DACE0) --------------------------------------------------------
void __thiscall aatree<short>::Insert(aatree<short> *this, char *name, __int16 *info, aatree<short>::aa_node **T, aatree<short>::aa_node *parent, int info_array_size)
{
	size_t v6; // eax@2
	aatree<short> *thisa; // [sp+0h] [bp-Ch]@1

	thisa = this;
	if (*T == this->null_node)
	{
		++this->num_nodes;
		*T = (aatree<short>::aa_node *)j__new(0x1Eu, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 189);
		v6 = strlen(name);
		(*T)->name = (char *)j__new(v6 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 190);
		strcpy((*T)->name, name);
		(*T)->info = info;
		(*T)->info_array_size = info_array_size;
		(*T)->right = thisa->null_node;
		(*T)->left = (*T)->right;
		(*T)->parent = parent;
		(*T)->level = 1;
		(*T)->visited = 0;
		return;
	}
	if (strcmp(name, (*T)->name) <= 0)
	{
		aatree<short>::Insert(thisa, name, info, &(*T)->left, *T, info_array_size);
	LABEL_8:
		aatree<short>::Skew(thisa, T);
		aatree<short>::Split(thisa, T);
		return;
	}
	if (strcmp(name, (*T)->name) > 0)
	{
		aatree<short>::Insert(thisa, name, info, &(*T)->right, *T, info_array_size);
		goto LABEL_8;
	}
}

//----- (008DAE60) --------------------------------------------------------
__int16 *__thiscall aatree<short>::Search(aatree<short> *this, char *name, aatree<short>::aa_node *cur)
{
	__int16 *result; // eax@2
	aatree<short> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (cur == this->null_node)
	{
		result = 0;
	}
	else
	{
		if (strcmp(name, cur->name))
		{
			if (strcmp(name, cur->name) >= 0)
				result = aatree<short>::Search(thisa, name, cur->right);
			else
				result = aatree<short>::Search(thisa, name, cur->left);
		}
		else
		{
			thisa->cur_visited = cur;
			result = cur->info;
		}
	}
	return result;
}

//----- (008DAEF0) --------------------------------------------------------
void __thiscall aatree<unsigned_char>::DeleteAll(aatree<unsigned char> *this, int delete_info)
{
	aatree<unsigned char> *v2; // ST08_4@1

	v2 = this;
	aatree<unsigned_char>::FreeTree(this, &this->root, delete_info);
	v2->root = v2->null_node;
}

//----- (008DAF20) --------------------------------------------------------
void __thiscall aatree<unsigned_char>::Insert(aatree<unsigned char> *this, char *name, char *info, aatree<unsigned char>::aa_node **T, aatree<unsigned char>::aa_node *parent, int info_array_size)
{
	size_t v6; // eax@2
	aatree<unsigned char> *thisa; // [sp+0h] [bp-Ch]@1

	thisa = this;
	if (*T == this->null_node)
	{
		++this->num_nodes;
		*T = (aatree<unsigned char>::aa_node *)j__new(0x1Eu, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 189);
		v6 = strlen(name);
		(*T)->name = (char *)j__new(v6 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 190);
		strcpy((*T)->name, name);
		(*T)->info = info;
		(*T)->info_array_size = info_array_size;
		(*T)->right = thisa->null_node;
		(*T)->left = (*T)->right;
		(*T)->parent = parent;
		(*T)->level = 1;
		(*T)->visited = 0;
		return;
	}
	if (strcmp(name, (*T)->name) <= 0)
	{
		aatree<unsigned_char>::Insert(thisa, name, info, &(*T)->left, *T, info_array_size);
	LABEL_8:
		aatree<unsigned_char>::Skew(thisa, T);
		aatree<unsigned_char>::Split(thisa, T);
		return;
	}
	if (strcmp(name, (*T)->name) > 0)
	{
		aatree<unsigned_char>::Insert(thisa, name, info, &(*T)->right, *T, info_array_size);
		goto LABEL_8;
	}
}

//----- (008DB0A0) --------------------------------------------------------
void __thiscall aatree<unsigned_char>::ResetParents(aatree<unsigned char> *this, aatree<unsigned char>::aa_node *cur, aatree<unsigned char>::aa_node *parent)
{
	aatree<unsigned char> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (!parent)
		parent = this->null_node;
	if (cur != this->null_node)
	{
		cur->parent = parent;
		aatree<unsigned_char>::ResetParents(this, cur->left, cur);
		aatree<unsigned_char>::ResetParents(thisa, cur->right, cur);
	}
}

//----- (008DB100) --------------------------------------------------------
int __thiscall aatree<unsigned_char>::Remove(aatree<unsigned char> *this, char *name, aatree<unsigned char>::aa_node **T, int delete_info, char *info)
{
	size_t v5; // eax@11
	signed int v6; // edx@19
	aatree<unsigned char> *thisa; // [sp+0h] [bp-14h]@1

	thisa = this;
	if (*T != this->null_node)
	{
		last_ptr = *T;
		if (strcmp(name, (*T)->name) >= 0)
		{
			del_ptr = *T;
			aatree<unsigned_char>::Remove(thisa, name, &(*T)->right, delete_info, info);
		}
		else
		{
			aatree<unsigned_char>::Remove(thisa, name, &(*T)->left, delete_info, info);
		}
		if (*T == last_ptr)
		{
			if (del_ptr == thisa->null_node || strcmp(name, del_ptr->name) || info && del_ptr->info != info)
			{
				item_found = 0;
			}
			else
			{
				operator delete(del_ptr->name);
				if (del_ptr != *T)
				{
					v5 = strlen((*T)->name);
					del_ptr->name = (char *)j__new(v5 + 1, "x:\\prj\\tech\\libsrc\\inputbnd\\aatree.h", 431);
					strcpy(del_ptr->name, (*T)->name);
					if (delete_info)
						operator delete(del_ptr->info);
					del_ptr->info_array_size = (*T)->info_array_size;
					del_ptr->info = (*T)->info;
				}
				*T = (*T)->right;
				del_ptr = thisa->null_node;
				operator delete(last_ptr);
				--thisa->num_nodes;
				item_found = 1;
			}
		}
		else
		{
			if ((*T)->left->level < (*T)->level - 1 || (*T)->right->level < (*T)->level - 1)
			{
				v6 = (*T)->right->level;
				--(*T)->level;
				if (v6 > (*T)->level)
					(*T)->right->level = (*T)->level;
				aatree<unsigned_char>::Skew(thisa, T);
				aatree<unsigned_char>::Skew(thisa, &(*T)->right);
				aatree<unsigned_char>::Skew(thisa, &(*T)->right->right);
				aatree<unsigned_char>::Split(thisa, T);
				aatree<unsigned_char>::Split(thisa, &(*T)->right);
			}
		}
	}
	return 1;
}

//----- (008DB3C0) --------------------------------------------------------
char *__thiscall aatree<unsigned_char>::Search(aatree<unsigned char> *this, char *name, aatree<unsigned char>::aa_node *cur)
{
	char *result; // eax@2
	aatree<unsigned char> *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	if (cur == this->null_node)
	{
		result = 0;
	}
	else
	{
		if (strcmp(name, cur->name))
		{
			if (strcmp(name, cur->name) >= 0)
				result = aatree<unsigned_char>::Search(thisa, name, cur->right);
			else
				result = aatree<unsigned_char>::Search(thisa, name, cur->left);
		}
		else
		{
			thisa->cur_visited = cur;
			result = cur->info;
		}
	}
	return result;
}

//----- (008DB450) --------------------------------------------------------
void __thiscall aatree<char>::Skew(aatree<char> *this, aatree<char>::aa_node **T)
{
	if ((*T)->left->level == (*T)->level)
		*T = aatree<char>::RotateWithLeftChild(this, *T);
}

//----- (008DB490) --------------------------------------------------------
void __thiscall aatree<char>::Split(aatree<char> *this, aatree<char>::aa_node **T)
{
	if ((*T)->right->right->level == (*T)->level)
	{
		*T = aatree<char>::RotateWithRightChild(this, *T);
		++(*T)->level;
	}
}

//----- (008DB4F0) --------------------------------------------------------
void __thiscall aatree<char>::FreeTree(aatree<char> *this, aatree<char>::aa_node **T, int delete_info)
{
	aatree<char> *thisa; // [sp+0h] [bp-10h]@1

	thisa = this;
	if (*T != this->null_node)
	{
		aatree<char>::FreeTree(this, &(*T)->left, delete_info);
		aatree<char>::FreeTree(thisa, &(*T)->right, delete_info);
		operator delete((*T)->name);
		--thisa->num_nodes;
		if (delete_info)
			operator delete((*T)->info);
		operator delete(*T);
		*T = thisa->null_node;
	}
}

//----- (008DB5A0) --------------------------------------------------------
void __thiscall aatree<short>::Skew(aatree<short> *this, aatree<short>::aa_node **T)
{
	if ((*T)->left->level == (*T)->level)
		*T = aatree<short>::RotateWithLeftChild(this, *T);
}

//----- (008DB5E0) --------------------------------------------------------
void __thiscall aatree<short>::Split(aatree<short> *this, aatree<short>::aa_node **T)
{
	if ((*T)->right->right->level == (*T)->level)
	{
		*T = aatree<short>::RotateWithRightChild(this, *T);
		++(*T)->level;
	}
}

//----- (008DB640) --------------------------------------------------------
void __thiscall aatree<short>::FreeTree(aatree<short> *this, aatree<short>::aa_node **T, int delete_info)
{
	aatree<short> *thisa; // [sp+0h] [bp-10h]@1

	thisa = this;
	if (*T != this->null_node)
	{
		aatree<short>::FreeTree(this, &(*T)->left, delete_info);
		aatree<short>::FreeTree(thisa, &(*T)->right, delete_info);
		operator delete((*T)->name);
		--thisa->num_nodes;
		if (delete_info)
			operator delete((*T)->info);
		operator delete(*T);
		*T = thisa->null_node;
	}
}

//----- (008DB6F0) --------------------------------------------------------
void __thiscall aatree<unsigned_char>::Skew(aatree<unsigned char> *this, aatree<unsigned char>::aa_node **T)
{
	if ((*T)->left->level == (*T)->level)
		*T = aatree<unsigned_char>::RotateWithLeftChild(this, *T);
}

//----- (008DB730) --------------------------------------------------------
void __thiscall aatree<unsigned_char>::Split(aatree<unsigned char> *this, aatree<unsigned char>::aa_node **T)
{
	if ((*T)->right->right->level == (*T)->level)
	{
		*T = aatree<unsigned_char>::RotateWithRightChild(this, *T);
		++(*T)->level;
	}
}

//----- (008DB790) --------------------------------------------------------
void __thiscall aatree<unsigned_char>::FreeTree(aatree<unsigned char> *this, aatree<unsigned char>::aa_node **T, int delete_info)
{
	aatree<unsigned char> *thisa; // [sp+0h] [bp-10h]@1

	thisa = this;
	if (*T != this->null_node)
	{
		aatree<unsigned_char>::FreeTree(this, &(*T)->left, delete_info);
		aatree<unsigned_char>::FreeTree(thisa, &(*T)->right, delete_info);
		operator delete((*T)->name);
		--thisa->num_nodes;
		if (delete_info)
			operator delete((*T)->info);
		operator delete(*T);
		*T = thisa->null_node;
	}
}

//----- (008DB840) --------------------------------------------------------
aatree<char>::aa_node *__thiscall aatree<char>::RotateWithLeftChild(aatree<char> *this, aatree<char>::aa_node *T)
{
	aatree<char>::aa_node *v2; // ST04_4@1

	v2 = T->left;
	T->left = v2->right;
	v2->right->parent = T;
	v2->right = T;
	v2->parent = T->parent;
	T->parent = v2;
	return v2;
}

//----- (008DB8A0) --------------------------------------------------------
aatree<char>::aa_node *__thiscall aatree<char>::RotateWithRightChild(aatree<char> *this, aatree<char>::aa_node *T)
{
	aatree<char>::aa_node *v2; // ST04_4@1

	v2 = T->right;
	T->right = v2->left;
	v2->left->parent = T;
	v2->left = T;
	v2->parent = T->parent;
	T->parent = v2;
	return v2;
}

//----- (008DB900) --------------------------------------------------------
aatree<short>::aa_node *__thiscall aatree<short>::RotateWithLeftChild(aatree<short> *this, aatree<short>::aa_node *T)
{
	aatree<short>::aa_node *v2; // ST04_4@1

	v2 = T->left;
	T->left = v2->right;
	v2->right->parent = T;
	v2->right = T;
	v2->parent = T->parent;
	T->parent = v2;
	return v2;
}

//----- (008DB960) --------------------------------------------------------
aatree<short>::aa_node *__thiscall aatree<short>::RotateWithRightChild(aatree<short> *this, aatree<short>::aa_node *T)
{
	aatree<short>::aa_node *v2; // ST04_4@1

	v2 = T->right;
	T->right = v2->left;
	v2->left->parent = T;
	v2->left = T;
	v2->parent = T->parent;
	T->parent = v2;
	return v2;
}

//----- (008DB9C0) --------------------------------------------------------
aatree<unsigned char>::aa_node *__thiscall aatree<unsigned_char>::RotateWithLeftChild(aatree<unsigned char> *this, aatree<unsigned char>::aa_node *T)
{
	aatree<unsigned char>::aa_node *v2; // ST04_4@1

	v2 = T->left;
	T->left = v2->right;
	v2->right->parent = T;
	v2->right = T;
	v2->parent = T->parent;
	T->parent = v2;
	return v2;
}

//----- (008DBA20) --------------------------------------------------------
aatree<unsigned char>::aa_node *__thiscall aatree<unsigned_char>::RotateWithRightChild(aatree<unsigned char> *this, aatree<unsigned char>::aa_node *T)
{
	aatree<unsigned char>::aa_node *v2; // ST04_4@1

	v2 = T->right;
	T->right = v2->left;
	v2->left->parent = T;
	v2->left = T;
	v2->parent = T->parent;
	T->parent = v2;
	return v2;
}
