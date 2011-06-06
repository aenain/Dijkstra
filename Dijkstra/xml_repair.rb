#!/Users/arturhebda/.rvm/rubies/ruby-1.9.2-p180/bin/ruby

dir = File.join %w{ / Users arturhebda Downloads }
file_name = ARGV.first || "map.osm"
file = File.join(dir, file_name)

puts "Reading file..."
source = File.read file

puts "Repairing tags..."
source = source.lines.to_a.each do |line|
  # Rule: one tag per line
  # "<tag ... />" => "<tag ...></tag>"
  line.gsub!(/<([[:alnum:]]+)(.*)\/>/, '<\1\2></\1>') if line =~ /\/>\s*$/
end

if source.first =~ /<\?xml/
  puts "Removing declaration of xml..."
  source.shift
end

puts "Writing file..."
File.open(file, 'w') do |file|
  file.write source.join
end