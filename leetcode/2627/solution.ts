// Beats 89%
type F = (...args: number[]) => void;

function debounce(fn: F, t: number): F {
  let id: ReturnType<typeof setTimeout> | null = null;

  return function (...args) {
    if (id !== null) {
      clearTimeout(id);
    }
    id = setTimeout(() => {
      fn(...args);
    }, t);
  };
}
