" Make keyword group contained {{{2
function! KeywordGroupContained(group) abort
  let x = split(execute("syntax list " . a:group), '\n')
  let y = index(map(deepcopy(x), 'v:val =~ ".*links to .*"'), 1)
  if y > 0
    let y = y-1
  endif
  let x = split(join(x[:y]))
  let x = x[index(x, 'xxx')+1:]
  execute "syntax clear ".a:group
  execute "syntax keyword ".a:group." contained ".join(x)
endfunction
