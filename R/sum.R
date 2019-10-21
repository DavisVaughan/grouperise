#' Compute a grouped sum
#'
#' @param x A numeric vector
#' @param g A vector defining grouping levels
#' @export
#' @examples
#' group_sum(mtcars$cyl, mtcars$vs)
#' group_sum(mtcars$cyl, mtcars[c("vs", "am")])
group_sum <- function(x, g) {
  if (vec_size(x) != vec_size(g)) {
    stop("`x` and `g` must be same size", call.  = FALSE)
  }

  split <- vec_split_id(g)
  idx <- split$id

  n <- vec_size(idx)

  .Call(grouped_sum_dbl, x, idx, n)
}
