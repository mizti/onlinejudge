# encoding: utf-8
require './island_counter'
while (line = gets)!=nil do
  w = line.split(" ")[0].to_i
  h = line.split(" ")[-1].to_i
  current_map = Array.new
  h.times do
    lat = gets
    current_map.push lat.split(" ").map{|i| i.to_i}
  end

  if current_map==[] then exit end

  ic = IslandCounter.new(current_map)
  p ic.explorer_all_islands

end
