#encode:utf-8
def perm(unselected, selected)
  result = [];
  if unselected.length == 0 then
    return selected
  else
    unselected.each_with_index{|elem,i|
      new_selected = selected.dup
      new_unselected = unselected.dup
      new_selected.push new_unselected.delete_at(i)
      result.push perm(new_unselected, new_selected)
    }
    return result;
  end
end

p perm([1,2,3],[])
