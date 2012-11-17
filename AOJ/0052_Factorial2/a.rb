# encoding: utf-8
require './island_counter'

current_map = Array.new
while (line = gets) do
line = line.chomp
  if line != "" then
    current_map.push line.split("").map{|i| i.to_i}
  else
    if current_map.size > 1 then
    ic = IslandCounter.new(current_map)
    p ic.explorer_all_islands
    current_map = Array.new
    end
  end
end
if current_map.size > 1 then
  ic = IslandCounter.new(current_map)
  p ic.explorer_all_islands
end
