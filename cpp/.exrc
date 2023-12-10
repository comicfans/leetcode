let s:cpo_save=&cpo
set cpo&vim
cnoremap <silent> <Plug>(TelescopeFuzzyCommandSearch) e "lua require('telescope.builtin').command_history { default_text = [=[" . escape(getcmdline(), '"') . "]=] }"
inoremap <silent> <C-^> =g:Vimim_onekey()
inoremap <C-_> =g:Vimim_chinese()
inoremap <silent> <expr> <Plug>delimitMateS-BS delimitMate#WithinEmptyPair() ? "\<Del>" : "\<S-BS>"
inoremap <silent> <Plug>delimitMateBS =delimitMate#BS()
imap <M-Bslash> <Plug>(copilot-suggest)
imap <M-[> <Plug>(copilot-previous)
imap <M-]> <Plug>(copilot-next)
imap <Plug>(copilot-suggest) <Cmd>call copilot#Suggest()
imap <Plug>(copilot-previous) <Cmd>call copilot#Previous()
imap <Plug>(copilot-next) <Cmd>call copilot#Next()
imap <Plug>(copilot-dismiss) <Cmd>call copilot#Dismiss()
inoremap <C-CR> ; 
imap <C-K> :pyf /usr/share/clang/clang-format.pyi
inoremap <C-W> u
inoremap <C-U> u
noremap <silent>  :EnableChanges
map  :Gvdiff 
map  :pyf /usr/share/clang/clang-format.py
nnoremap  <Cmd>nohlsearch|diffupdate|normal! 
map  :w 
tmap  
xnoremap <silent>  y:call g:Vimim_visual()
nnoremap <silent>  i=g:Vimim_chinese()
map  tt <Plug>AM_tt
map  tsq <Plug>AM_tsq
map  tsp <Plug>AM_tsp
map  tml <Plug>AM_tml
map  tab <Plug>AM_tab
map  m= <Plug>AM_m=
map  tW@ <Plug>AM_tW@
map  t@ <Plug>AM_t@
map  t~ <Plug>AM_t~
map  t? <Plug>AM_t?
map  w= <Plug>AM_w=
map  ts= <Plug>AM_ts=
map  ts< <Plug>AM_ts<
map  ts; <Plug>AM_ts;
map  ts: <Plug>AM_ts:
map  ts, <Plug>AM_ts,
map  t= <Plug>AM_t=
map  t< <Plug>AM_t<
map  t; <Plug>AM_t;
map  t: <Plug>AM_t:
map  t, <Plug>AM_t,
map  t# <Plug>AM_t#
map  t| <Plug>AM_t|
map  T~ <Plug>AM_T~
map  Tsp <Plug>AM_Tsp
map  Tab <Plug>AM_Tab
map  TW@ <Plug>AM_TW@
map  T@ <Plug>AM_T@
map  T? <Plug>AM_T?
map  T= <Plug>AM_T=
map  T< <Plug>AM_T<
map  T; <Plug>AM_T;
map  T: <Plug>AM_T:
map  Ts, <Plug>AM_Ts,
map  T, <Plug>AM_T,o
map  T# <Plug>AM_T#
map  T| <Plug>AM_T|
map  Htd <Plug>AM_Htd
map  anum <Plug>AM_aunum
map  aenum <Plug>AM_aenum
map  aunum <Plug>AM_aunum
map  afnc <Plug>AM_afnc
map  adef <Plug>AM_adef
map  adec <Plug>AM_adec
map  ascom <Plug>AM_ascom
map  aocom <Plug>AM_aocom
map  adcom <Plug>AM_adcom
map  acom <Plug>AM_acom
map  abox <Plug>AM_abox
map  a( <Plug>AM_a(
map  a= <Plug>AM_a=
map  a< <Plug>AM_a<
map  a, <Plug>AM_a,
map  a? <Plug>AM_a?
nnoremap <silent>  q :QToggle
nnoremap <silent>  l :LToggle
map  rwp <Plug>RestoreWinPosn
map  swp <Plug>SaveWinPosn
map  di <Plug>DrawItStart
nmap <nowait> <silent>  H <Plug>(ChangesStageHunkRevert)
nmap <nowait> <silent>  h <Plug>(ChangesStageHunk)
nnoremap  fd <Cmd>lua vim.lsp.buf.code_action()
nnoremap  kk <Cmd>ClangdSwitchSourceHeader
nnoremap  fj <Cmd>Telescope live_grep
nnoremap  fs <Cmd>Telescope lsp_workspace_symbols
nnoremap  fk <Cmd>Telescope oldfiles
nnoremap  ff <Cmd>Telescope find_files
nmap  j <Cmd>HopWord
nnoremap  n :NnnPicker '%:p:h' 
map  k <Plug>(Man)
nmap <silent>  i <Plug>IndentGuidesToggle
xnoremap # y?\V"
omap <silent> % <Plug>(MatchitOperationForward)
xmap <silent> % <Plug>(MatchitVisualForward)
nmap <silent> % <Plug>(MatchitNormalForward)
nnoremap & :&&
xnoremap * y/\V"
nnoremap Y y$
omap <silent> [% <Plug>(MatchitOperationMultiBackward)
xmap <silent> [% <Plug>(MatchitVisualMultiBackward)
nmap <silent> [% <Plug>(MatchitNormalMultiBackward)
map <silent> <expr> [h changes#MoveToNextChange(0, v:count1)
omap <silent> ]% <Plug>(MatchitOperationMultiForward)
xmap <silent> ]% <Plug>(MatchitVisualMultiForward)
nmap <silent> ]% <Plug>(MatchitNormalMultiForward)
map <silent> <expr> ]h changes#MoveToNextChange(1, v:count1)
xmap a% <Plug>(MatchitVisualTextObject)
omap <silent> ah :norm Vah
vmap <silent> <expr> ah changes#CurrentHunk()
map fk :
xmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
omap <silent> g% <Plug>(MatchitOperationBackward)
xmap <silent> g% <Plug>(MatchitVisualBackward)
nmap <silent> g% <Plug>(MatchitNormalBackward)
xmap <silent> gi 
nnoremap <silent> gi a=g:Vimim_gi()
nnoremap <silent> n :call g:Vimim_search()n
nnoremap <SNR>106_: :=v:count ? v:count : ''
xnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(netrw#GX(),netrw#CheckIfRemote(netrw#GX()))
xmap <silent> <Plug>(MatchitVisualTextObject) <Plug>(MatchitVisualMultiBackward)o<Plug>(MatchitVisualMultiForward)
onoremap <silent> <Plug>(MatchitOperationMultiForward) :call matchit#MultiMatch("W",  "o")
onoremap <silent> <Plug>(MatchitOperationMultiBackward) :call matchit#MultiMatch("bW", "o")
xnoremap <silent> <Plug>(MatchitVisualMultiForward) :call matchit#MultiMatch("W",  "n")m'gv``
xnoremap <silent> <Plug>(MatchitVisualMultiBackward) :call matchit#MultiMatch("bW", "n")m'gv``
nnoremap <silent> <Plug>(MatchitNormalMultiForward) :call matchit#MultiMatch("W",  "n")
nnoremap <silent> <Plug>(MatchitNormalMultiBackward) :call matchit#MultiMatch("bW", "n")
onoremap <silent> <Plug>(MatchitOperationBackward) :call matchit#Match_wrapper('',0,'o')
onoremap <silent> <Plug>(MatchitOperationForward) :call matchit#Match_wrapper('',1,'o')
xnoremap <silent> <Plug>(MatchitVisualBackward) :call matchit#Match_wrapper('',0,'v')m'gv``
xnoremap <silent> <Plug>(MatchitVisualForward) :call matchit#Match_wrapper('',1,'v'):if col("''") != col("$") | exe ":normal! m'" | endifgv``
nnoremap <silent> <Plug>(MatchitNormalBackward) :call matchit#Match_wrapper('',0,'n')
nnoremap <silent> <Plug>(MatchitNormalForward) :call matchit#Match_wrapper('',1,'n')
tnoremap <silent> <Plug>(fzf-normal) 
tnoremap <silent> <Plug>(fzf-insert) i
nnoremap <silent> <Plug>(fzf-normal) <Nop>
nnoremap <silent> <Plug>(fzf-insert) i
nmap <SNR>71_WE <Plug>AlignMapsWrapperEnd
map <SNR>71_WS <Plug>AlignMapsWrapperStart
nnoremap <Plug>PlenaryTestFile :lua require('plenary.test_harness').test_file(vim.fn.expand("%:p"))
xnoremap <silent> <C-^> y:call g:Vimim_visual()
nnoremap <silent> <C-_> i=g:Vimim_chinese()
nmap <silent> <Plug>RestoreWinPosn :call RestoreWinPosn()
nmap <silent> <Plug>SaveWinPosn :call SaveWinPosn()
noremap <silent> <Plug>DrawItStop :set lz:call DrawIt#DrawItStop():set nolz
noremap <silent> <Plug>DrawItStart :set lz:call DrawIt#DrawItStart():set nolz
nnoremap <SNR>50_ChangesStageHunkRevert :call changes#StageHunk(line('.'), 1)
nnoremap <SNR>50_ChangesStageHunkAdd :call changes#StageHunk(line('.'), 0)
tnoremap <C-BS> <BS>
tnoremap <S-BS> <BS>
tnoremap <C-Space>  
tnoremap <S-Space>  
nnoremap <F2> :SymbolsOutline
map <F12> :NERDTreeToggle                 
map <F3> :NERDTreeFind    
map <C-G> :Gvdiff 
map <C-S> :w 
map <C-K> :pyf /usr/share/clang/clang-format.py
noremap <silent> <C-C> :EnableChanges
nnoremap <C-L> <Cmd>nohlsearch|diffupdate|normal! 
imap  :pyf /usr/share/clang/clang-format.pyi
inoremap  u
inoremap  u
inoremap <silent>  =g:Vimim_onekey()
inoremap  =g:Vimim_chinese()
imap jk 
let &cpo=s:cpo_save
unlet s:cpo_save
set cmdheight=2
set completeopt=menu,menuone,noselect
set diffopt=internal,filler,closeoff,vertical
set equalprg=clang-format\ -
set expandtab
set grepprg=rg\ --vimgrep
set helplang=en
set ignorecase
set runtimepath=~/.config/nvim,~/.vim/bundle/onedark.vim,~/.vim/bundle/vim-code-dark,~/.vim/bundle/everforest,~/.vim/bundle/copilot.vim,~/.vim/bundle/nord-vim,~/.vim/bundle/vim-monokai,~/.vim/bundle/neovim-gui-shim,~/.vim/bundle/delimitMate,~/.vim/bundle/vim-es6,~/.vim/bundle/nerdtree,~/.vim/bundle/vim-go,~/.vim/bundle/Jenkinsfile-vim-syntax,~/.vim/bundle/DoxygenToolkit.vim,~/.vim/bundle/Nvim-R,~/.vim/bundle/changesPlugin,~/.vim/bundle/DrawIt,~/.vim/bundle/VimIM,~/.vim/bundle/AnsiEsc.vim,~/.vim/bundle/vim-dispatch,~/.vim/bundle/clangd_extensions.nvim,~/.vim/bundle/echodoc.vim,~/.vim/bundle/vim-autopep8,~/.vim/bundle/nvim-treesitter,~/.vim/bundle/nvim-lspconfig,~/.vim/bundle/cmp-buffer,~/.vim/bundle/cmp-path,~/.vim/bundle/cmp-cmdline,~/.vim/bundle/cmp-nvim-lsp,~/.vim/bundle/lsp_signature.nvim,~/.vim/bundle/nvim-cmp,~/.vim/bundle/symbols-outline.nvim,~/.vim/bundle/LuaSnip,~/.vim/bundle/cmp_luasnip,~/.vim/bundle/rust-tools.nvim,~/.vim/bundle/popup.nvim,~/.vim/bundle/plenary.nvim,~/.vim/bundle/telescope.nvim,~/.vim/bundle/telescope-fzf-native.nvim,~/.vim/bundle/telescope-ui-select.nvim,~/.vim/bundle/nvim-web-devicons,~/.vim/bundle/trouble.nvim,~/.vim/bundle/vim-fugitive,~/.vim/bundle/hop.nvim,~/.vim/bundle/ListToggle,~/.vim/bundle/vim-glsl,~/.vim/bundle/ack.vim,~/.vim/bundle/Align,~/.vim/bundle/vim-markdown,~/.vim/bundle/lightline.vim,~/.vim/bundle/nvim-dap,~/.vim/bundle/nvim-dap-virtual-text,~/.vim/bundle/nvim-dap-ui,/etc/xdg/nvim,~/.local/share/nvim/site,~/.local/share/flatpak/exports/share/nvim/site,/var/lib/flatpak/exports/share/nvim/site,/usr/local/share/nvim/site,/usr/share/nvim/site,/usr/share/nvim/runtime,/usr/share/nvim/runtime/pack/dist/opt/matchit,/usr/lib/nvim,/usr/share/nvim/site/after,/usr/local/share/nvim/site/after,/var/lib/flatpak/exports/share/nvim/site/after,~/.local/share/flatpak/exports/share/nvim/site/after,~/.local/share/nvim/site/after,/etc/xdg/nvim/after,~/.config/nvim/after,~/.vim/bundle/cmp-buffer/after,~/.vim/bundle/cmp-path/after,~/.vim/bundle/cmp-cmdline/after,~/.vim/bundle/cmp-nvim-lsp/after,~/.vim/bundle/cmp_luasnip/after,~/.vim/bundle/vim-glsl/after,/usr/share/vim/vimfiles/
set shiftwidth=4
set smartcase
set tabline=%!lightline#tabline()
set tabstop=4
set termguicolors
set undodir=~/.vim/undodir
set undofile
set undolevels=500
set updatetime=300
set window=54
" vim: set ft=vim :
