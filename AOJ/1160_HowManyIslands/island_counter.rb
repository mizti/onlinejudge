class IslandCounter
  attr_accessor :map
  def initialize(map)
    @map = map
  end
  def neighbors(y, x)
    w = map[0].length
    h = map.length
    neighbor_list =[[y-1, x-1], [y-1, x], [y-1, x+1], [y, x-1], [y, x+1], [y+1, x-1], [y+1, x], [y+1, x+1]]
    return neighbor_list.select{|i| i[0] >= 0 && i[0]<h && i[1] >=0 && i[1]<w }.select{|i| @map[i[0]][i[1]] == 1 } 
  end
  
  def num_island_color 
    @map.flatten.sort.uniq.select{|i|i!=0}.length
  end

  def explorer_all_islands
    while (coord = find_new_island) != nil do
      explorer_in_an_island(coord[0], coord[1])
    end
    return num_island_color
  end

  def explorer_in_an_island(y, x, new_color = largest_color + 1)
    @map[y][x] = new_color
    neighbors(y, x).each{|coords| 
      explorer_in_an_island(coords[0], coords[1], new_color)
    }
  end

  def find_new_island
    if @map.flatten.include?(1) then
       h = @map.length
       w = @map[0].length
       place = @map.flatten.index(1)
       return [place / w, place % w]
    else
       return nil
    end
  end
  def largest_color
    @map.flatten.sort.max
  end
end
