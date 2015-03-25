MRuby::Gem::Specification.new('mruby-win-mouse') do |spec|
  spec.license = 'MIT'
  spec.authors = 'bamchoh'

  spec.linker do |linker|
    linker.libraries = %w(user32)
  end
end
