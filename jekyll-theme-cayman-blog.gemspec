# encoding: utf-8

Gem::Specification.new do |s|
  s.name          = "jekyll-theme-cayman-blog"
  s.version       = "0.0.6"
  s.license       = "CC0-1.0"
  s.authors       = ["Eoghan Byrne"]
  s.email         = ["info@dragontech.ie"]
  s.homepage      = "http://dragontech.ie"
  s.summary       = "Welcome to dragontech.ie"

  s.files         = `git ls-files -z`.split("\x0").select do |f|
    f.match(%r{^((_includes|_layouts|_sass|assets)/|(LICENSE|README|index|about|contact|404)((\.(txt|md|markdown)|$)))}i)
  end

  s.platform      = Gem::Platform::RUBY
  s.add_runtime_dependency "jekyll", "~> 3.3"
end
