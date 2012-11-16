require 'rspec'
class ColonyCounter
  attr_accessor :map
  def initialize(map)
    @map = map
  end
  def neighbors(y, x)
    w = map[0].length
    h = map.length
    neighbor_list =[[y-1, x], [y, x-1], [y, x+1], [y+1, x]]
    return neighbor_list.select{|i| i[0] >= 0 && i[0]<h && i[1] >=0 && i[1]<w }
  end
  def browse(y, x)
    new_color = 0
    if map[y][x] == 1 then
      new_color = largest_color + 1
      map[y][x] = new_color
    elsif map[y][x] > 1 then
      new_color = map[y][x]
    end
    neighbors(y, x).each{|target|
      if map[target[0]][target[1]] == 1 then
        map[target[0]][target[1]] = new_color
        browse(target[0], target[1])
      end
    }
  end
  def find_new_colony
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

while (line = gets)!=nil do
  w = line.split(" ")[0].to_i
  h = line.split(" ")[-1].to_i
  current_map = Array.new
  h.times do
    lat = gets
    current_map.push lat.split(" ").map{|i| i.to_i}
  end
  if current_map==[] then exit end
  cc = ColonyCounter.new(current_map)
  while(coord = cc.find_new_colony) do
    cc.browse(coord[0], coord[1])
  end
  puts cc.map.flatten.sort.uniq.select{|i|i!=0}.length.to_s
end

describe ColonyCounter do
  it "should have map as array" do
    ic = ColonyCounter.new([[1],[1]])
    ic.map.class.should == Array
  end
  it "should return neighbors" do
    ic = ColonyCounter.new([[1,1],[1,1],[0,8]])
    ic.map.length.should == 3
    ic.map[0].length.should == 2
    ic.neighbors(0,0).should == [[0,1],[1,0],[1,1]]
    ic.neighbors(1,1).should == [[0,0],[0,1],[1,0]]
  end

  it "should return neighbors2" do
    ic = ColonyCounter.new([[1,1,1],[1,1,1],[1,0,1],[1,1,1]])
    ic.neighbors(0,0).should == [[0,1],[1,0],[1,1]]
    ic.neighbors(3,2).should == [[2,2],[3,1]]
    ic.neighbors(1,1).should == [[0,0],[0,1],[0,2],[1,0],[1,2],[2,0],[2,2]]
  end
  it "should return neighbors" do
    ic = ColonyCounter.new([[0]])
    ic.neighbors(0,0).should == []
  end
  it "should return a new color" do
    ic = ColonyCounter.new([[2,3,3],[1,2,3],[0,8,3],[5,63,3]])
    ic.largest_color.should == 63
  end
  it "should return from explorering" do
    ic = ColonyCounter.new([[1,1,1],[1,0,1],[0,0,0],[1,1,1]])
    ic.explorer_in_an_colony(0,0)
    ic.map.should == [[2, 2, 2], [2, 0, 2], [0, 0, 0], [1, 1, 1]]
  end
  it "should return from explorering" do
    ic = ColonyCounter.new([[2, 2, 2], [2, 0, 2], [0, 0, 0], [1, 1, 1]])
    ic.explorer_in_an_colony(3,1)
    ic.map.should == [[2, 2, 2], [2, 0, 2], [0, 0, 0], [3, 3, 3]]
  end

  it "should return the coord of new colony" do
    ic = ColonyCounter.new([[2, 2, 2], [2, 0, 2], [0, 0, 0], [1, 1, 1]])
    ic.find_new_colony.should == [3, 0]
  end
  it "should return the coord of new colony" do
    ic = ColonyCounter.new([[2, 2, 2], [2, 0, 2], [0, 0, 0], [0, 1, 1]])
    ic.find_new_colony.should == [3, 1]
  end
  it "should return nil if there is no remaining unexplorered colony" do
    ic = ColonyCounter.new([[2, 2, 2], [2, 0, 2], [0, 0, 0], [3, 3, 3]])
    ic.find_new_colony.should == nil
  end
end

